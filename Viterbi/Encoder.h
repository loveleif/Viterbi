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
// Output to input rate ratio
#define ENCODER_n 2
// Number of states
#define NUMBER_OF_STATES 4
/*
Some good generator polynomials
{{  0x6,  0x7 },  K = 3
 {  0xD,  0xE },  K = 4
 { 0x1A, 0x1D },  K = 5
 { 0x35, 0x3B }}; K = 6
 */

static int generator_polynomial[ENCODER_n][K] = {
  { 1, 1, 1 },  { 1, 0, 1 }
};

int output_table[NUMBER_OF_STATES][ENCODER_n];

Message falt_encoder(Data data);
Message memory_falt_encoder(Data data);
void init_encoding_table();
void init_output_table();
#endif