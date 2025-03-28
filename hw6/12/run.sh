#!/bin/bash
cd /home/rv/
make CLIENT_C_SRC=../12/main.c CLIENT_S_SRC=../12/sum_odd.s TARGET=../12/main 1>&2
qemu-riscv32 ../12/main $@
