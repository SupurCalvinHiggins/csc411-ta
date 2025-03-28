#include "rv_int.h"

int16_t abs16(int16_t x) { return x < 0 ? -x : x; }

int16_t l1_dist(int16_t *A, int16_t *B, int n) {
  int16_t sum = 0;
  for (int i = 0; i < n; i++) {
    sum += abs16(A[i] - B[i]);
  }
  return sum;
}
