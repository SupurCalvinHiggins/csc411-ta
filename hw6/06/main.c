#include "rv_stdio.h"
#include "rv_str.h"
#include "rv_syscall.h"

int deadbeef(void);

int main(int argc, char *argv[]) {
  (void)argv;

  if (argc != 1) {
    rv_puts("Usage: ./main\n");
    rv_exit(1);
  }

  int ans = deadbeef();

  char buf[12];
  rv_int_to_str(ans, buf, sizeof(buf) / sizeof(buf[0]));
  rv_puts(buf);
  rv_putc('\n');

  return 0;
}
