#!/bin/bash
cd /home/rv/
make CLIENT_C_SRC="../05/main.c ../05/ss.c" TARGET=../05/main 1>&2
qemu-riscv32 ../05/main $@
