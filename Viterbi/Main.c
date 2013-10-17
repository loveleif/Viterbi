#include<stdio.h>
#include "Source.h"
#include "Encoder.h"
#include "Util.h"
#include "Decoder.h"
int main() {
  int in, out;
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
  */

  in = 0x5C; out = falt_encoder(in);
  printf("%s -> ", byte_to_binary(in, 8));
  printf("%s\n", byte_to_binary(out, 20));
  //viterbi_decoder(0x1);

	printf("\n");
	return 0;
}