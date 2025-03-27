#include "rv_stdio.h"
#include "rv_str.h"
#include "rv_syscall.h"

int multiply(int x, int y);

int main(int argc, char *argv[]) {
  if (argc != 3) {
    rv_puts("Usage: ./main <x> <y>\n");
    rv_exit(1);
  }

  int x = rv_str_to_int(argv[1]);
  int y = rv_str_to_int(argv[2]);
  int z = multiply(x, y);

  char buf[12];
  rv_int_to_str(z, buf, sizeof(buf) / sizeof(buf[0]));
  rv_puts(buf);
  rv_putc('\n');

  return 0;
}
