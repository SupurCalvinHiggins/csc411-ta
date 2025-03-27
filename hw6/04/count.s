.section .text
.globl count 

# int count(const char* s, int (*f)(char));
count:
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
  jalr x0, s3, 0
