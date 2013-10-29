#include "Util.h"
#define RAND_DIGITS 15

/*
void print_binary(int x, int digits) {
  int i;
  for (i = digits; i != 0; --i) {
    if ((x >> i) & 1)
      printf("1");
    else
      printf("0");
  }
}
*/

char* byte_to_binary(int x, int digits, int group) {
  int i;
  static char buffer[127];
  char* current = buffer;

  for (i = 0; i < digits; ++i) {
    if ((x >> digits - i - 1) & 1)
      *current = '1';
    else
      *current = '0';
    if (group > 0 && (i+1) % group == 0) *++current = ' ';
    ++current;
  }
  *current = '\0';
  return buffer;
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