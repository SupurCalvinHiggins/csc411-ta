#include "rv_int.h"
#include "rv_stdio.h"
#include "rv_str.h"
#include "rv_syscall.h"

void apply(int *A, int n, int (*f)(int));
void reduce(int *A, int n, int (*f)(int, int), int *acc);

int id(int x) { return x; }
int neg(int x) { return -x; }

int sum(int acc, int x) { return acc + x; }
int prod(int acc, int x) { return acc * x; }

int main(int argc, char *argv[]) {
  if (argc < 4) {
    rv_puts("Usage: ./main <apply_mode> <reduce_mode> <acc> <A[0]> <A[1]> ... "
            "<A[n-1]>\n");
    rv_exit(1);
  }

  int apply_mode = rv_str_to_int(argv[1]);
  if (apply_mode != 0 && apply_mode != 1) {
    rv_puts("Usage: apply_mode must be 0 or 1");
    rv_exit(1);
  }

  int reduce_mode = rv_str_to_int(argv[2]);
  if (reduce_mode != 0 && reduce_mode != 1) {
    rv_puts("Usage: reduce_mode must be 0 or 1");
    rv_exit(1);
  }

  int acc = rv_str_to_int(argv[3]);

  int (*apply_f)(int) = apply_mode ? neg : id;
  int (*reduce_f)(int, int) = reduce_mode ? prod : sum;

  int n = argc - 4;

  int A[n];
  for (int i = 4; i < argc; ++i) {
    A[i - 4] = rv_str_to_int(argv[i]);
  }

  apply(A, n, apply_f);
  reduce(A, n, reduce_f, &acc);

  char buf[12];
  rv_int_to_str(acc, buf, sizeof(buf) / sizeof(buf[0]));
  rv_puts(buf);
  rv_putc('\n');

  return 0;
}
