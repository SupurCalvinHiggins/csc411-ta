#include "rv_stdio.h"
#include "rv_str.h"
#include "rv_syscall.h"

int sign(int num);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    rv_puts("Usage: ./main <x>\n");
    rv_exit(1);
  }

  int x = rv_str_to_int(argv[1]);
  x = sign(x);

  char buf[12];
  rv_int_to_str(x, buf, sizeof(buf) / sizeof(buf[0]));
  rv_puts(buf);
  rv_putc('\n');

  return 0;
}
