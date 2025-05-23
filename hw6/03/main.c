#include "rv_int.h"
#include "rv_stdio.h"
#include "rv_str.h"
#include "rv_syscall.h"

void negative(int16_t *A, int n);
int sum(int16_t *A, int n);

int main(int argc, char *argv[]) {
  if (argc == 0) {
    rv_puts("Usage: ./main <A[0]> <A[1]> ... <A[n-1]>\n");
    rv_exit(1);
  }

  int n = argc - 1;

  int16_t A[n];
  for (int i = 1; i < argc; ++i) {
    A[i - 1] = rv_str_to_int(argv[i]);
  }

  negative(A, n);
  int t = sum(A, n);

  char buf[12];
  rv_int_to_str(t, buf, sizeof(buf) / sizeof(buf[0]));
  rv_puts(buf);
  rv_putc('\n');

  return 0;
}
