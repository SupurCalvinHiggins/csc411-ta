#!/bin/bash
cd /home/rv/
make CLIENT_C_SRC="../03/main.c ../03/negative.c" TARGET=../03/main 1>&2
qemu-riscv32 ../03/main $@
