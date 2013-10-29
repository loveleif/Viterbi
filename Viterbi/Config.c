#include "Config.h"
#include "Encoder.h"
#include "DecoderBrute.h"
#include <assert.h>

void decoder_test() {
  int i;
  for (i = 0; i < DATA_MAX; ++i) {
    //printf("   assert data = %d   poly1 = %d   poly2 = %d\n", i, generator_polynomial[0], generator_polynomial[1]);
    //printf("   data = %s\n", byte_to_binary(i, DATA_SIZE, 0));
    //printf("   enc  = %s\n", byte_to_binary(falt_encoder(i), MESSAGE_SIZE, ENCODER_n));
    assert(i == brute_force_viterbi_decoder(memory_falt_encoder(i)));
  }
}

void init() {
  generator_polynomial = (int*) malloc(ENCODER_n * sizeof(int));
  
  assert(ENCODER_n == 2);
  generator_polynomial[0] = GEN_POLY_0;
  generator_polynomial[1] = GEN_POLY_1;

  init_output_table();
  init_encoding_table();
  //decoder_test();
}

void re_init() {
  init_output_table();
  init_encoding_table();
  decoder_test();
}