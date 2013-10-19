#include "Encoder.h"

enum encoder_state { UNINITIALIZED, INITIALIZED };
enum encoder_state this_encoder_state = UNINITIALIZED;

Message encoding_table[256];

/*
int output_table[4][2] = { 
// Input: 0  1
		 {0, 3}, // Current state = 00
		 {3, 0}, // Current state = 01
		 {2, 1}, // Current state = 10
		 {1, 2}  // Current state = 11 
};
*/

void init_output_table() {
  int state, window, input, digit, output, p, n;
  for (input = 0; input != 2; ++input) {
    for (state = 0; state != NUMBER_OF_STATES; ++state) {
      output_table[state][input] = 0;
      for (n = 0; n != ENCODER_n; ++n) {
        output = INT_MAX;
        window = state | (input << m);
        for (p = K - 1; p != -1; --p) {
          if (generator_polynomial[n][p]) {
            if (output == INT_MAX) 
              output = window & 1;
            else 
              output ^= window & 1;
          }
          window >>= 1;
        }
        output_table[state][input] <<= 1;
        output_table[state][input] |= output;
      }
    }
  }
}

Message falt_encoder(Data data) {
	int state = 0, input, output, i, bit;
	Message message = 0;

	for (i = DATA_SIZE - 1; i != -1; --i) {
		input = (data >> i) & 1;

		output = output_table[state][input];
    //output = input ^ 
		
    message <<= m;
    message |= output;
    
    // Next state
    state = (state >> 1);
    state |= input << 1;
	}
  message <<= 2*m;
	return message;
}

Message memory_falt_encoder(Data data) {
  if (this_encoder_state == UNINITIALIZED)
    init_encoding_table();
  return encoding_table[data];
}

void init_encoding_table() {
  int i;
  for (i = 0; i < 256; ++i)
    encoding_table[i] = falt_encoder(i);
}
