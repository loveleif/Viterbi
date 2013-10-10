#include "Encoder.h"
#include<stdio.h>

int falt_output_table[4][2] = { 
// Input: 0  1
		 {0, 3}, // Current state = 00
		 {3, 0}, // Current state = 01
		 {2, 1}, // Current state = 10
		 {1, 2}  // Current state = 11 
};
int falt_state_table[4][2] = { 
// Input: 0  1
		   {0, 2}, // Current state = 00
	     {0, 2}, // Current state = 01
	     {1, 3}, // Current state = 10
	     {1, 3}  // Current state = 11 
};

Message falt_encoder(Data data) {
	int state = 0, input, output, i, bit;
	Message message = 0;

	for (i = 7; i != -1; --i) {
		input = (data >> i) & 1;
		state = falt_state_table[state][input];
		output = falt_output_table[state][input];
		message |= output << 2*i;
	}
	return message;
}
