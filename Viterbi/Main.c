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
  int i, in, out, outerr, decoded, errors = 0;
  int in, out, i, j;

  init_output_table();
  init_encoding_table();
  /*
  in = 0; out = falt_encoder(in);
  printf("%d -> %d\n", in, out);
	printf("%s -> ", byte_to_binary(in));
  printf("%s\n", byte_to_binary(out));

  in = 1; out = falt_encoder(in);
  printf("%d -> %d\n", in, out);
	printf("%s -> ", byte_to_binary(in));
  printf("%s\n", byte_to_binary(out));

  in = 3; out = falt_encoder(in);
  printf("%d -> %d\n", in, out);
	printf("%s -> ", byte_to_binary(in));
  printf("%s\n", byte_to_binary(out));

  in = 11; out = falt_encoder(in);
  printf("%d -> %d\n", in, out);
	printf("%s -> ", byte_to_binary(in));
  printf("%s\n", byte_to_binary(out));

  for (i = 0; i < 10000; ++i) {
	  in = random_in_range(0, 0xFF);
	  out = memory_falt_encoder(in);
	  outerr = out ^ (1 << random_in_range(0,8));
	  outerr = outerr ^ (1 << random_in_range(0,8));
	  decoded = brute_force_viterbi_decoder(outerr);
	  if (decoded != in) ++errors;
	  //printf("decoded: %d   in: %d   outerr: %d\n", decoded, in, inerr);
  }
  printf("Errors: %d", errors);
  /*
  in = 0x5C; out = falt_encoder(in);
  printf("%s -> ", byte_to_binary(in, 8));
  printf("%s\n", byte_to_binary(out, 20));

  printf("  Kod: %s\n", byte_to_binary(in, 8));
  printf("Avkod: %s\n", byte_to_binary(brute_force_viterbi_decoder(out), 8));
  */

  //viterbi_decoder(0x1);

  for (i = 0; i != NUMBER_OF_STATES; ++i) {
    for (j = 0; j != ENCODER_n; ++j) {
      printf("%d   ", output_table[i][j]);
    }
    printf("\n");
  }

	printf("\n");
	return 0;
}