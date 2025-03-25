.section .text
.globl rv_write
.globl rv_exit

rv_write:
  addi a7, x0, 64
  ecall
  ret

rv_exit:
  addi a7, x0, 93
  ecall
  jal x0, 0
