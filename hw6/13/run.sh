#!/bin/bash
cd /home/rv/
make CLIENT_C_SRC=../13/main.c CLIENT_S_SRC=../13/multiply.s TARGET=../13/main 1>&2
qemu-riscv32 ../13/main $@
