.section .text
.globl negative 
.globl sum 

# void negative(int16_t* A, int n);
negative:
  # TODO: complete negative.c
  addi t0, x0, 0
  blt t0, a1, L1
L0:
  lh t1, 0(a0)
  sub t1, x0, t1
  sh t1, 0(a0)
  addi a0, a0, 2
  addi t0, t0, 1
  bne t0, a1, L0
L1:
  ret

# int sum(int16_t* A, int n);
sum:
  # TODO: complete negative.c
  slli a1, a1, 1
  add a1, a0, a1 
  addi t0, x0, 0
  bgeu a0, a1, L3
L2:
  lh t1, 0(a0)
  add t0, t0, t1
  addi a0, a0, 2
  bne a0, a1, L2
L3:
  ret
