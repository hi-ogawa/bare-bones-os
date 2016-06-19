CFLAGS = -I./include -std=gnu99 -ffreestanding -O2 -Wall -Wextra

CSRCS = string.c kernel.c terminal.c gdt.c idt.c isrs.c io.c dump.c timer.c keyboard.c
OBJS = $(CSRCS:.c=.o)

.DEFAULT_GOAL = myos.iso

%.o: %.c
	i686-elf-gcc $(CFLAGS) -c $< -o $@

boot.o: boot.s
	i686-elf-as boot.s -o boot.o

myos.bin: boot.o $(OBJS)
	i686-elf-gcc boot.o $(OBJS) -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib -lgcc

myos.iso: myos.bin isodir/boot/grub/grub.cfg
	cp myos.bin isodir/boot/myos.bin
	grub-mkrescue -o myos.iso isodir

clean:
	rm -f boot.o $(OBJS) myos.bin isodir/boot/myos.bin myos.iso
