#include<stdio.h>
#include "Config.h"
#include "Source.h"
#include "Encoder.h"
#include "Util.h"
#include "Decoder.h"
#include "DecoderBrute.h"
#include <assert.h>

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

void print_simu_head() {
  int i;
  printf("K;m;ENCODER_n;NUMBER_OF_STATES;DATA_SIZE;MESSAGE_SIZE;Runs;BitErrorProbability;TransmittedBits;TransmittedBytes;BitErrors;BitErrorRate;ByteErrors;ByteErrorRate");
  for (i = 0; i < ENCODER_n; ++i) printf(";poly%d", i);
  printf("\n");
}

void simu(double min_bit_error, double max_bit_error, double bit_error_step, int n) {
  double bit_error_rate;
  int i, dist, bit_errors, data_errors;
  Data data;
  Message message;
  if (n % DATA_MAX != 0) n = (DATA_MAX + 1) * (n / DATA_MAX);

  for (bit_error_rate = min_bit_error; bit_error_rate <= max_bit_error; bit_error_rate += bit_error_step) {
    bit_errors = 0;
    data_errors = 0;
    for (i = 0; i < n; ++i) {
      data = i % DATA_MAX;
      message = bit_error(memory_falt_encoder(data), bit_error_rate, MESSAGE_SIZE);
      dist = hamdist(data, brute_force_viterbi_decoder(message));
      bit_errors += dist;
      if (dist) ++data_errors;
    }
    printf("%d;%d;%d;%d;%d;%d;%d;%f;%d;%d;%d;%f;%d;%f", K, m, ENCODER_n, NUMBER_OF_STATES, DATA_SIZE, MESSAGE_SIZE, n, bit_error_rate, n*MESSAGE_SIZE, n, bit_errors, ((double) bit_errors)/(((double)n)*DATA_SIZE), data_errors, ((double) data_errors)/n);
    for (i = 0; i < ENCODER_n; ++i) printf(";%d", generator_polynomial[i]);
    printf("\n");

  }
}


void best_poly(double min_bit_error, double max_bit_error, double bit_error_step, int n) {
  int poly = 0;
  int test_poly, test_poly_correct, useless;
  int poly_max = 2, i, j, k, mask = 0;
  
  for (i = 0; i < ENCODER_n * K-1; ++i) poly_max *= 2;
  for (i = 0; i < K; ++i) { mask <<= 1; mask |= 1; }

  print_simu_head();
  for (i = 0; i < poly_max; ++i) {
    poly = i;
    test_poly = 0;
    useless = 0;
    for (j = 0; j < ENCODER_n; ++j) {
      generator_polynomial[j] = poly & mask;
      test_poly |= generator_polynomial[j];
      if (!generator_polynomial[j]) { useless = 1; break; }
      poly >>= K;
    }
    // Fulhack
    if (generator_polynomial[0] > generator_polynomial[1] && test_poly == mask && !useless) {
      re_init();
      simu(min_bit_error, max_bit_error, bit_error_step, n);
    }
  }
}

int main() {
  int i;
  init();

  best_poly(0.01, 0.201, 0.01, DATA_MAX * 50);

	printf("\n");
	return 0;
}