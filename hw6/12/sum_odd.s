.section .text
.globl sum_odd 

# int sum_odd(int n);
sum_odd:
  # TODO: if n > 0, return 1 + 3 + ... + (2n - 1).
  # TODO: otherwise, return 0.
hang:
  j hang
