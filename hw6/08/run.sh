#!/bin/bash
cd /home/rv/
make CLIENT_C_SRC=../08/main.c CLIENT_S_SRC=../08/l1_dist.s TARGET=../08/main 1>&2
qemu-riscv32 ../08/main $@
