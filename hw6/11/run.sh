#!/bin/bash
cd /home/rv/
make CLIENT_C_SRC=../11/main.c CLIENT_S_SRC=../11/negative.s TARGET=../11/main 1>&2
qemu-riscv32 ../11/main $@
