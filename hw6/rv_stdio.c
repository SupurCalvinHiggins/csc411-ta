#include "rv_syscall.h"

void rv_putc(char c) {
  char buf[1] = {c};
  rv_write(1, &buf, 1);
}

void rv_puts(char *s) {
  int len = 0;
  while (s[len] != 0)
    ++len;
  rv_write(1, s, len);
}
