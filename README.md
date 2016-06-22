[![Build Status](https://travis-ci.org/hi-ogawa/bare-bones-os.svg?branch=master)](https://travis-ci.org/hi-ogawa/bare-bones-os)

Minimal kernel experiment following two tutorials:

- [OSDev Wiki: Bare Bones](http://wiki.osdev.org/Bare_Bones),
- [Bran's Kernel Development](http://www.osdever.net/bkerndev/Docs/title.htm).

Details are told in [my blog post](http://wp.hiogawa.net/2016/06/19/os-development-starter/).

Development:

- Use [QEMU](http://wiki.qemu.org/Main_Page) from Mac OS, which is installed by `brew install qemu`
- Use my custom vagrant box [hiogawa/os_dev](https://atlas.hashicorp.com/hiogawa/boxes/os_dev/) for
  - gcc cross compiler for _i686-elf_ and
  - grub utility `grub-mkrescue`

```
$ vagrant up
$ vagrant ssh
> cd /vagrant/workdir
> make
> exit
$ qemu-system-i386 -cdrom workdir/myos.iso
```

On QEMU, after you choose _myos_ from GRUB loader, you can type in on screen:

![](http://wp.hiogawa.net/wp-content/uploads/2016/06/os_demo-1.gif)
