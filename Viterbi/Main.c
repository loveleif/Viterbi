#include<stdio.h>
#include "Source.h"
#include "Encoder.h"
#include "Util.h"
#include "Decoder.h"
#include "DecoderBrute.h"
int main() {
  int in, out, i, j;
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

  in = 0x5C; out = falt_encoder(in);
  printf("%s -> ", byte_to_binary(in, 8));
  printf("%s\n", byte_to_binary(out, 20));

  printf("  Kod: %s\n", byte_to_binary(in, 8));
  printf("Avkod: %s\n", byte_to_binary(brute_force_viterbi_decoder(out), 8));
  */

  //viterbi_decoder(0x1);

  init_output_table();
  for (i = 0; i != NUMBER_OF_STATES; ++i) {
    for (j = 0; j != ENCODER_n; ++j) {
      printf("%d   ", output_table[i][j]);
    }
    printf("\n");
  }

	printf("\n");
	return 0;
}