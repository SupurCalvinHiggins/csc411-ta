#!/bin/bash
cd /home/rv/
make CLIENT_C_SRC="../02/main.c ../02/twosum.c" TARGET=../02/main 1>&2
qemu-riscv32 ../02/main $@
