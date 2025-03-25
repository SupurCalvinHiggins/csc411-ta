#include "rv_assert.h"
#include "rv_stdio.h"
#include "rv_str.h"

int main(int argc, char *argv[]) {
  rv_putc('h');
  rv_puts("ello world!\n");

  char buf[16];

  rv_int_to_str(123456, buf, 16);
  rv_assert(rv_str_to_int(buf) == 123456);
  rv_puts(buf);
  rv_putc('\n');

  rv_int_to_str(-123456, buf, 16);
  rv_assert(rv_str_to_int(buf) == -123456);
  rv_puts(buf);
  rv_putc('\n');

  rv_int_to_str(0, buf, 16);
  rv_assert(rv_str_to_int(buf) == 0);
  rv_puts(buf);
  rv_putc('\n');

  buf[0] = '-';
  buf[1] = '0';
  buf[2] = 0;
  rv_assert(rv_str_to_int(buf) == 0);

  while (1)
    ;
}
