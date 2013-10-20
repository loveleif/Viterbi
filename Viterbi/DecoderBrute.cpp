#include "Decoder.h"
#include <limits.h>

int hamdist(int x, int y) {
  int dist = 0, val = x ^ y; // XOR
 
  // Count the number of set bits
  while(val) {
    ++dist; 
    val &= val - 1;
  }
  return dist;
}

Data brute_force_viterbi_decoder(Message data) {
  int min_dist = INT_MAX;
  int dist;
  Data best_fit;
  int i;
  for (i = 0; i < DATA_MAX; ++i) {
    dist = hamdist(memory_falt_encoder(i), data);
    if (dist < min_dist) {
      min_dist = dist;
      best_fit = i;
      if (min_dist == 0) break;
    }
  }
  return best_fit;
}