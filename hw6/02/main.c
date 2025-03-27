#include "rv_stdio.h"
#include "rv_str.h"
#include "rv_syscall.h"

int twosum(int a, int b, int c, int t);

int main(int argc, char *argv[]) {
  if (argc != 4) {
    rv_puts("Usage: ./main <a> <b> <c> <t>\n");
    rv_exit(1);
  }

  int a = rv_str_to_int(argv[1]);
  int b = rv_str_to_int(argv[2]);
  int c = rv_str_to_int(argv[3]);
  int t = rv_str_to_int(argv[4]);
  int ans = twosum(a, b, c, t);

  char buf[12];
  rv_int_to_str(ans, buf, sizeof(buf) / sizeof(buf[0]));
  rv_puts(buf);
  rv_putc('\n');

  return 0;
}
