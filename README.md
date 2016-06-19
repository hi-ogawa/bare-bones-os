[![Build Status](https://travis-ci.org/hi-ogawa/bare-bones-os.svg?branch=master)](https://travis-ci.org/hi-ogawa/bare-bones-os)

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
> make
> exit
$ qemu-system-i386 -cdrom workdir/myos.iso
```

On QEMU, after you choose _myos_ from GRUB loader, this screen will show up:

![](https://cloud.githubusercontent.com/assets/4232207/16175397/a8b55170-3626-11e6-884d-355e6079fa94.png)
