#!/bin/bash
cd /home/rv/
make CLIENT_C_SRC="../04/main.c ../04/count.c" TARGET=../04/main 1>&2
qemu-riscv32 ../04/main $@
