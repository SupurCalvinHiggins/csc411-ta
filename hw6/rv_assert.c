#include "rv_syscall.h"

void rv_assert(int cond) {
  if (!cond) {
    rv_exit(-1);
  }
}
