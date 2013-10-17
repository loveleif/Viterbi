#include "Encoder.h"

enum encoder_state { UNINITIALIZED, INITIALIZED };
enum encoder_state this_encoder_state = UNINITIALIZED;

Message encoding_table[256];

int output_table[4][2] = { 
// Input: 0  1
		 {0, 3}, // Current state = 00
		 {3, 0}, // Current state = 01
		 {2, 1}, // Current state = 10
		 {1, 2}  // Current state = 11 
};

Message falt_encoder(Data data) {
	int state = 0, input, output, i, bit;
	Message message = 0;

	for (i = DATA_SIZE - 1; i != -1; --i) {
		input = (data >> i) & 1;
		output = output_table[state][input];
		message <<= m;
    message |= output;
    
    state = (state >> 1);
    state |= input << 1;
	}
  message <<= 2*m;
	return message;
}

Message memory_falt_encoder(Data data) {
  if (this_encoder_state == UNINITIALIZED)
    initialize_encoding_table();
  return encoding_table[data];
}

void initialize_encoding_table() {
  int i;
  for (i = 0; i < 256; ++i)
    encoding_table[i] = falt_encoder(i);
}