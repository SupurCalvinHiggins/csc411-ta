#include "rv_assert.h"

int rv_str_to_int(const char *s) {
  int neg = *s == '-';
  if (neg) {
    ++s;
    rv_assert(*s != 0);
  }

  int x = 0;
  while (*s != 0) {
    x *= 10;
    rv_assert(*s >= '0' && *s <= '9');
    x += *s - '0';
    s++;
  }

  return neg ? -x : x;
}

void rv_int_to_str(int x, char *buf, int n) {
  rv_assert(n >= 2);

  if (x == 0) {
    buf[0] = '0';
    buf[1] = 0;
    return;
  }

  int neg = x < 0;
  if (neg)
    x = -x;

  buf[n - 1] = 0;

  int i = n - 2;
  while (x != 0 && i >= neg) {
    buf[i] = x % 10 + '0';
    x /= 10;
    --i;
  }

  if (neg) {
    buf[i] = '-';
    --i;
  }

  rv_assert(x == 0);

  for (int j = 0; j < n - i - 1; ++j) {
    buf[j] = buf[i + j + 1];
  }
}
