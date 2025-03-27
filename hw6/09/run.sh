#!/bin/bash
cd /home/rv/
make CLIENT_C_SRC="../09/main.c" CLIENT_S_SRC="../09/functools.s" TARGET=../09/main 1>&2
qemu-riscv32 ../09/main $@
