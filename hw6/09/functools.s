.section .text
.globl apply 
.globl reduce 

# void apply(int *A, int n, int (*f)(int));
apply:
  # TODO: return the same as functools.c
  j hang

# void reduce(int *A, int n, int (*f)(int, int), int *acc);
reduce:
  # TODO: return the same as functools.c
  j hang

hang:
  j hang
