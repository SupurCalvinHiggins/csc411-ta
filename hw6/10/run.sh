#!/bin/bash
cd /home/rv/
make CLIENT_C_SRC=../10/main.c CLIENT_S_SRC=../10/ss.s TARGET=../10/main 1>&2
qemu-riscv32 ../10/main $@
