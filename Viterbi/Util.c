#include "Util.h"

/* http://stackoverflow.com/a/112956 */
char* byte_to_binary(int x) {
  int z;
  static char b[9];
  b[0] = '\0';

  for (z = 128; z > 0; z >>= 1) {
    strcat(b, ((x & z) == z) ? "1" : "0");
   }

  return b;
}