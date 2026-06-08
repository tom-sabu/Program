#include <stdio.h>

static unsigned long x = 123456789;

unsigned long xorshift() {
  x ^= x << 13;
  return x;
}

int main() {
  printf("binary of 123456789 after shifting 13 times: %lu\n", xorshift());
  return 0;
}
