.section .text
.globl ms 
.globl ss 

# int ms(const char *s, const char *p);
ms:
  # TODO: complete ss.c
L0:
  lbu t0, 0(a0)
  lbu t1, 0(a1)
  beq t1, x0, L2
  beq t0, x0, L1
  bne t0, t1, L1
  addi a0, a0, 1
  addi a1, a1, 1
  j L0
L1:
  addi a0, x0, 0 
  ret
L2:
  addi a0, x0, 1
  ret

# char *ss(const char *s, const char *p);
ss:
  # TODO: complete ss.c
  addi sp, sp, -16
  sw s0, 0(sp)
  sw s1, 4(sp)
  sw s2, 8(sp)
  addi s0, a0, 0
  addi s1, a1, 0
  addi s2, ra, 0
L3:
  addi a0, s0, 0
  addi a1, s1, 0
  call ms
  bne a0, x0, L4
  addi s0, s0, 1
  lbu t0, 0(s0)
  bne t0, x0, L3
  addi a0, x0, 0
  j L5
L4:
  addi a0, s0, 0
L5:
  addi ra, s2, 0
  lw s0, 0(sp)
  lw s1, 4(sp)
  lw s2, 8(sp)
  addi sp, sp, 16
  ret
