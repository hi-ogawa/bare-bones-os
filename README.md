Minimal kernel experiment following http://wiki.osdev.org/Bare_Bones.

Notes:

- Use [QEMU](http://wiki.qemu.org/Main_Page) from Mac OS, which is installed by `brew install qemu`
- cross compiler toolchain for i686-elf is called from docker containers ([hiogawa/i686-elf:4.9.3](https://hub.docker.com/r/hiogawa/i686-elf/))
- grub utility is called from vagrant

Commands:

```
$ docker run -it --rm -v $PWD/workdir:/srv/workdir -w /srv/workdir hiogawa/i686-elf:4.9.3
# i686-elf-as boot.s -o boot.o
# i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
# i686-elf-gcc -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc
# exit
$ vagrant up
$ vagrant ssh
# cd /vagrant/workdir
# cp myos.bin isodir/boot/myos.bin
# grub-mkrescue -o myos.iso isodir
# exit
$ qemu-system-i386 -cdrom workdir/myos.iso
```
