#!/bin/bash
cd /home/rv/
make CLIENT_C_SRC=../14/main.c CLIENT_S_SRC=../14/sum.s TARGET=../14/main 1>&2
qemu-riscv32 ../14/main $@
