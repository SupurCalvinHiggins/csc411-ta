#include "rv_int.h"

void apply(int *A, int n, int (*f)(int)) {
  for (int i = 0; i < n; ++i) {
    A[i] = f(A[i]);
  }
}

void reduce(int *A, int n, int (*f)(int, int), int *acc) {
  for (int i = 0; i < n; ++i) {
    *acc = f(*acc, A[i]);
  }
}
