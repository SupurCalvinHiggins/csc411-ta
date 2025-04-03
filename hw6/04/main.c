#include "rv_stdio.h"
#include "rv_str.h"
#include "rv_syscall.h"

int count(const char *s, int (*f)(char));

int is_any(char c) {
  (void)c;
  return 1;
}

int is_vowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int is_upper(char c) { return c >= 'A' && c <= 'Z'; }

int main(int argc, char *argv[]) {
  if (argc != 3) {
    rv_puts("Usage: ./main <mode> <s>\n");
    rv_exit(1);
  }

  int mode = rv_str_to_int(argv[1]);
  if (mode < 0 || mode > 2) {
    rv_puts("Usage: filter_mode must be 0, 1 or 2\n");
    rv_exit(1);
  }
  int (*fs[3])(char) = {is_any, is_vowel, is_upper};
  int (*f)(char) = fs[mode];

  char *s = argv[2];

  int t = count(s, f);

  char buf[12];
  rv_int_to_str(t, buf, sizeof(buf) / sizeof(buf[0]));
  rv_puts(buf);
  rv_putc('\n');

  return 0;
}
