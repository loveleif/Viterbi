#ifndef VITERBI_ENCODER_H
#define VITERBI_ENCODER_H

#include "Data.h"
#include "Util.h"
#include<stdio.h>

// The "length" of the convolutional encoder, i.e. how many k-bit stages are 
// available to feed the combinatorial logic that produces the output symbols
#define K 3
// Number of encoder cycles an input bit is retained and used for encoding 
// after it first appears at the input to the convolutional encoder
#define m 2
// Number of states
#define NUMBER_OF_STATES 4

int output_table[4][2];
int next_state_table[4][2];

Message falt_encoder(Data data);

#endif