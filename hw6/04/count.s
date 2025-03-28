.section .text
.globl count 

# int count(const char* s, int (*f)(char));
count:
  addi sp, sp, -16
  sw s0, 0(sp)
  sw s1, 4(sp)
  sw s2, 8(sp)
  sw s3, 12(sp)
  addi s0, a0, 0
  addi s1, a1, 0
  addi s2, x0, 0
  addi s3, ra, 0
L0:
  lbu a0, 0(s0)
  beq a0, x0, L1
  jalr ra, s1, 0
  add s2, s2, a0
  addi s0, s0, 1
  j L0
L1:
  addi a0, s2, 0
  addi ra, s3, 0
  lw s0, 0(sp)
  lw s1, 4(sp)
  lw s2, 8(sp)
  lw s3, 12(sp)
  addi sp, sp, 16
  ret
