.section .text
.globl twosum 

# int twosum(int a, int b, int c, int t);
twosum:
  # TODO: complete twosum.c
  add t0, a0, a1
  sub t0, t0, a3
  beq t0, x0, L1
  add t0, a0, a2
  sub t0, t0, a3
  beq t0, x0, L1
  add t0, a1, a2
  sub t0, t0, a3
  beq t0, x0, L1
  addi a0, x0, 0
  ret
L1:
  addi a0, x0, 1
  ret
