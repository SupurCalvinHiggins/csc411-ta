#include "rv_stdio.h"
#include "rv_str.h"
#include "rv_syscall.h"

int sum_odd(int n);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    rv_puts("Usage: ./main <n>\n");
    rv_exit(1);
  }

  int n = rv_str_to_int(argv[1]);
  int t = sum_odd(n);

  char buf[12];
  rv_int_to_str(t, buf, sizeof(buf) / sizeof(buf[0]));
  rv_puts(buf);
  rv_putc('\n');

  return 0;
}
