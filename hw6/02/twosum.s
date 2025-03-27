.section .text
.globl twosum 

# int twosum(int a, int b, int c, int t);
not:
  # TODO: complete twosum.c
  addi a5, a0, 0
  addi a0, x0, 0
  add t0, a1, a2
  sub t0, t0, a3
  beq t0, x0, L1
  add t0, a1, a5
  sub t0, t0, a3
  beq t0, x0, L1
  add t0, a2, a5
  sub t0, t0, a3
  beq t0, x0, L1
  ret
L1:
  addi a0, x0, 1
  ret
