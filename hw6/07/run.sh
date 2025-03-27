#!/bin/bash
cd /home/rv/
make CLIENT_C_SRC=../07/main.c CLIENT_S_SRC=../07/sign.s TARGET=../07/main 1>&2
qemu-riscv32 ../07/main $@
