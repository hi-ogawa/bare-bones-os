# create header following multiboot specification to use GRUB as a boot loader
# https://www.gnu.org/software/grub/manual/multiboot/multiboot.html#Header-magic-fields

.section .multiboot
.align 4
.long 0x1BADB002                    # magic number
.long 1<<0 | 1<<1                   # some control option flags
.long -(0x1BADB002 + (1<<0 | 1<<1)) # checksum


# prepare stack for c program `_kernel_main`

.section .bootstrap_stack, "aw", @nobits
.skip 16384 # 16 KiB
stack_top:


# `linker.ld` points this section as ENTRY

.section .text
.global _start
_start:
	movl $stack_top, %esp
	call kernel_main
	cli
	hlt
.Lhang:
	jmp .Lhang


# load GDT

.global gdt_flush # gdt_flush will be called from kernel.c
gdt_flush:
  # TODO: difference of `gdtp` and `$gdtp`
	lgdt (gdtp) # gdtp is defined in gdt.c
	mov $0x10, %eax # TODO: what is "0x10"
	# commenting-out those lines also works
	mov %eax, %ss
	mov %eax, %ds
	mov %eax, %es
	mov %eax, %fs
	mov %eax, %gs
	# TODO: what is "0x08" ?
	jmp $0x08, $gdt_flush_ret
	# jmp gdt_flush_ret
	# this also works
	# ljmp $0x08, $gdt_flush_ret
gdt_flush_ret:
	ret

# NOTE: far jump
#  - http://x86.renejeschke.de/html/file_module_x86_id_147.html
#  - https://en.wikipedia.org/wiki/JMP_(x86_instruction)
