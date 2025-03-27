.section .text
.globl not 

# int not(int x);
not:
  # TODO: complete not.c
  xori a0, a0, -1
  ret
