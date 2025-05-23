#include "rv_stdio.h"
#include "rv_str.h"
#include "rv_syscall.h"
#include <stdint.h>

int16_t l1_dist(int16_t *A, int16_t *B, int n);

int main(int argc, char *argv[]) {
  if (argc == 0 || (argc & 1) != 1) {
    rv_puts(
        "Usage: ./main <A[0]> <B[0]> <A[1]> <B[1]> ... <A[n-1]> <B[n-1]>\n");
    rv_exit(1);
  }

  int n = (argc - 1) >> 1;

  int16_t A[n];
  int16_t B[n];
  for (int i = 0; i < n; ++i) {
    A[i] = rv_str_to_int(argv[(i << 1) + 1]);
    B[i] = rv_str_to_int(argv[(i << 1) + 2]);
  }

  int t = l1_dist(A, B, n);

  char buf[12];
  rv_int_to_str(t, buf, sizeof(buf) / sizeof(buf[0]));
  rv_puts(buf);
  rv_putc('\n');

  return 0;
}
