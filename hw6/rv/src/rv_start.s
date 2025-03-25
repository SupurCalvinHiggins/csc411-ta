.section .text
.globl _start

_start:

    # init bss
    la a0, __bss_start
    la a1, __bss_end

bss_init:
    bge a0, a1, bss_init_done
    sw x0, 0(a0)
    addi a0, a0, 4
    j bss_init

bss_init_done:

    # init args 
    lw a0, 0(sp)    # argc
    addi a1, sp, 4  # argv

    # align stack
    andi t0, sp, 15
    beq t0, x0, sp_init_done
    andi sp, sp, -16
    addi sp, sp, 16
sp_init_done:

    # main
    call main

    # exit
    li a0, 0
    call rv_exit
