all: myos.iso

clean:
	rm boot.o kernel.o string.o myos.bin isodir/boot/myos.bin

boot.o: boot.s
	i686-elf-as boot.s -o boot.o

string.o: string.c
	i686-elf-gcc -c string.c -I./include -o string.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

kernel.o: kernel.c
	i686-elf-gcc -c kernel.c -I./include -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

myos.bin: boot.o kernel.o string.o
	i686-elf-gcc boot.o string.o kernel.o -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib -lgcc

myos.iso: myos.bin isodir/boot/grub/grub.cfg
	cp myos.bin isodir/boot/myos.bin
	grub-mkrescue -o myos.iso isodir
