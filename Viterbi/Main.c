#include "Config.h"
#include<stdio.h>
#include "Source.h"
#include "Encoder.h"
#include "Util.h"
#include "Decoder.h"
#include "DecoderBrute.h"

#define LOOP_N 50000

/* Would like a semi-open interval [min, max) */
int random_in_range(unsigned int min, unsigned int max) {
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

int bit_error(int in, double bit_error_prob, int digits) {
  int errors = 0;
  int thres = bit_error_prob * RAND_MAX;
  while (digits > 0) {
    errors <<= 1;
    if (rand() <= thres) errors |= 1;
    --digits;
  }
  return errors ^ in;
}

int main() {
  int i, j, in, out, outerr, decoded, dist;
  int bit_errors = 0, byte_errors = 0;
  double bit_error_prob;
  init_output_table();
  init_encoding_table();
  
  /*
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
  */
  
  printf("K;m;ENCODER_n;NUMBER_OF_STATES;DATA_SIZE;MESSAGE_SIZE;Runs;BitErrorProbability;TransmittedBits;TransmittedBytes;BitErrors;BitErrorRate;ByteErrors;ByteErrorRate\n");
  for (bit_error_prob = 0.01; bit_error_prob <= 0.20; bit_error_prob += 0.01) {
    bit_errors = 0; byte_errors = 0;
    for (i = 0; i < LOOP_N; ++i) {
      in = random_in_range(0, DATA_MAX);
	    out = memory_falt_encoder(in);
      outerr = bit_error(out, bit_error_prob, MESSAGE_SIZE);
	    decoded = brute_force_viterbi_decoder(outerr);
	    dist = hamdist(in, decoded);
      bit_errors += dist;
      if (dist) ++byte_errors;
    }
    //printf("%f\n", ((double) byte_errors)/LOOP_N);
    printf("%d;%d;%d;%d;%d;%d;%d;%f;%d;%d;%d;%f;%d;%f\n", K, m, ENCODER_n, NUMBER_OF_STATES, DATA_SIZE, MESSAGE_SIZE, LOOP_N, bit_error_prob, LOOP_N*MESSAGE_SIZE, LOOP_N, bit_errors, ((double) bit_errors)/(((double)LOOP_N)*DATA_SIZE), byte_errors, ((double) byte_errors)/LOOP_N);
  }  
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