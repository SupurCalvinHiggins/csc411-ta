.section .text
.globl dot 

# int dot(int* A, int* B, int n);
dot:
  # TODO: return the dot product between A and B.
  # NOTE: the dot product is A[0] * B[0] + A[1] * B[1] + ... + A[n-1] * B[n-1].
hang:
  j hang
