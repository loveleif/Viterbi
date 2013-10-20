#include "Util.h"
#define RAND_DIGITS 15

char* byte_to_binary(int x, int digits) {
  int i;
  static char out[64];
  
  for (i = 0; i < digits; ++i) {
    if ((x >> digits - i - 1) & 1)
      out[i] = '1';
    else
      out[i] = '0';
  }
  out[digits] = '\0';
  return out;
}

/*
static int random;
static int bits_left = 0;
char random_bit() {
  if (bits_left <= 0) {
    random = rand();
    bits_left = RAND_DIGITS;
  }
  random >> 1;
  --bits_left;
  return random & 1;
}
*/