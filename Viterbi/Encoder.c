#include "Encoder.h"

enum encoder_state { UNINITIALIZED, INITIALIZED };
enum encoder_state this_encoder_state = UNINITIALIZED;



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
  return encoding_table[data];
}

void init_encoding_table() {
  int i;
  for (i = 0; i < DATA_MAX; ++i)
    encoding_table[i] = falt_encoder(i);
}
