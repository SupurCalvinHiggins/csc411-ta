#!/bin/bash
cd /home/rv/
make CLIENT_C_SRC="../01/main.c ../01/not.c" TARGET=../01/main 1>&2
qemu-riscv32 ../01/main $@
