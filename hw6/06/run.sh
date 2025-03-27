#!/bin/bash
cd /home/rv/
make CLIENT_C_SRC=../06/main.c CLIENT_S_SRC=../06/deadbeef.s TARGET=../06/main 1>&2
qemu-riscv32 ../06/main $@
