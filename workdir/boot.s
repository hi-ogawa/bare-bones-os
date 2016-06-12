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
