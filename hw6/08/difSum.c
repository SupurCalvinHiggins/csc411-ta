#include "rv_int.h"

int16_t difSum(int16_t *A, int16_t *B, int n) {
  int16_t sum = 0;
  for (int i = 0; i < n; i++) {
      sum += (A[i] - B[i]);
  }
  return sum;
}
