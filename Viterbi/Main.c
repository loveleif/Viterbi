#include<stdio.h>
#include "Source.h"
#include "Encoder.h"
#include "Util.h"
#include "Decoder.h"
#include "DecoderBrute.h"

/* Would like a semi-open interval [min, max) */
int random_in_range(unsigned int min, unsigned int max)
{
	  int range       = max - min,
      remainder   = RAND_MAX % range,
      bucket      = RAND_MAX / range;
	int base_random = rand(); /* in [0, RAND_MAX] */
  if (RAND_MAX == base_random) return random_in_range(min, max);
  /* now guaranteed to be in [0, RAND_MAX) */

  /* There are range buckets, plus one smaller interval
     within remainder of RAND_MAX */
  if (base_random < RAND_MAX - remainder) {
    return min + base_random/bucket;
  } else {
    return random_in_range (min, max);
  }
}

int main() {
  int i, j, in, out, outerr, decoded, errors = 0;

  init_output_table();
  init_encoding_table();
  
  printf("K = %d\n", K);
  printf("m = %d\n", m);
  printf("ENCODER_n = %d\n", ENCODER_n);
  printf("NUMBER_OF_STATES = %d\n", NUMBER_OF_STATES);
  printf("generator_polynomial:\n");
  for (i = 0; i < ENCODER_n; ++i) {
    printf("{ ");
    for (j = 0; j < K; ++j) {
      printf(" %d ", generator_polynomial[i][j]);
    }
    printf(" }\n");
  }

  printf("\n\n");

  for (i = 0; i < 100000; ++i) {
    in = random_in_range(0, DATA_MAX);
	  out = memory_falt_encoder(in);
    outerr = out ^ (1 << random_in_range(0,DATA_SIZE));
	  decoded = brute_force_viterbi_decoder(outerr);
	  if (decoded != in) ++errors;
	  //printf("decoded: %d   in: %d   outerr: %d\n", decoded, in, inerr);
  }
  printf("Errors: %d\n", errors);
  
  /*
  for (i = 0; i != NUMBER_OF_STATES; ++i) {
    for (j = 0; j != ENCODER_n; ++j) {
      printf("%d   ", output_table[i][j]);
    }
    printf("\n");
  }
  */
	printf("\n");
	return 0;
}