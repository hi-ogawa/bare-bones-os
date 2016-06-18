#!/bin/bash

docker run -v $PWD/workdir:/srv/workdir -w /srv/workdir hiogawa/i686-elf:4.9.3 make myos.bin
