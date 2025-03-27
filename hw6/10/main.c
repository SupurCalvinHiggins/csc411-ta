#include "rv_assert.h"
#include "rv_stdio.h"
#include "rv_str.h"
#include "rv_syscall.h"

int ms(const char *s, const char *p);
char *ss(const char *s, const char *p);

int main(int argc, char *argv[]) {
  if (argc != 3) {
    rv_puts("Usage: ./main <s> <p>\n");
    rv_exit(1);
  }

  char *s = argv[1];
  char *p = argv[2];

  char *b = ss(s, p);
  if (b == 0) {
    return 0;
  }
  rv_assert(ms(b, p));

  int idx = b - s;

  char buf[12];
  rv_int_to_str(idx, buf, sizeof(buf) / sizeof(buf[0]));
  rv_puts(buf);
  rv_putc('\n');

  return 0;
}
