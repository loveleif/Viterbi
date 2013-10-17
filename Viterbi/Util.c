#include "Util.h"


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