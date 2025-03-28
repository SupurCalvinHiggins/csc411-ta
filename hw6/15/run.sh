#!/bin/bash
cd /home/rv/
make CLIENT_C_SRC=../15/main.c CLIENT_S_SRC=../15/dot.s TARGET=../15/main 1>&2
qemu-riscv32 ../15/main $@
