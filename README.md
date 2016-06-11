Minimal kernel experiment following http://wiki.osdev.org/Bare_Bones.

Notes:

- Use [QEMU](http://wiki.qemu.org/Main_Page) from Mac OS, which is installed by `brew install qemu`
- Use [my custom vagrant box: hiogawa/os_dev](https://atlas.hashicorp.com/hiogawa/boxes/os_dev/) for
  - gcc cross compiler for _i686-elf_ and
  - grub utility `grub-mkrescue`

Commands:

```
$ vagrant up
$ vagrant ssh
> cd /vagrant/workdir
> i686-elf-as boot.s -o boot.o
> i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
> i686-elf-gcc -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc
> cp myos.bin isodir/boot/myos.bin
> grub-mkrescue -o myos.iso isodir
> exit
$ qemu-system-i386 -cdrom workdir/myos.iso
```
