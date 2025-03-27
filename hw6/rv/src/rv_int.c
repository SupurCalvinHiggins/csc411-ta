#include "rv_int.h"

int32_t __mulsi3(int32_t x, int32_t y) {
  int32_t res = 0;
  int neg = (x < 0) ^ (y < 0);

  if (x < 0)
    x = -x;
  if (y < 0)
    y = -y;

  while (y) {
    if (y & 1)
      res += x;
    x <<= 1;
    y >>= 1;
  }

  return neg ? -res : res;
}

uint32_t __umodsi3(uint32_t x, uint32_t y) {
  uint32_t res = x;
  while (res >= y) {
    res -= y;
  }
  return res;
}

int32_t __modsi3(int32_t x, int32_t y) {
  if (x > 0 && y > 0) {
    return __umodsi3(x, y);
  } 
  else if (x < 0 && y < 0) {
    return -__umodsi3(-x, -y);
  }

  int32_t res = x;
  int neg = y < 0;
  if (neg) {
    x = -x;
    y = -y;
  }
  while (res < y) {
    res += y;
  }

  return neg ? -res : res;
}

uint32_t __udivsi3(uint32_t x, uint32_t y) {
  int res = 0;
  while (x >= y) {
    x -= y;
    ++res;
  }
  return res;
}

int32_t __divsi3(int32_t x, int32_t y) {
  int neg = (x < 0) ^ (y < 0);
  if (x < 0)
    x = -x;
  if (y < 0)
    y = -y;

  int res = __udivsi3(x, y);
  return neg ? -res : res;
}
