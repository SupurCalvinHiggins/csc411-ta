.section .text
.globl sum 

# int sum(int8_t* A, int n);
sum:
  # TODO: return A[0] + A[1] + ... A[n-1].
hang:
  j hang
