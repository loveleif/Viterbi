#ifndef VITERBI_CONFIG_H
#define VITERBI_CONFIG_H

#define VITERBI_CONFIG_K4

/*
CONFIGURATION TEMPLATE
======================

#define DATA_SIZE 8
#define DATA_MAX 255
#define MESSAGE_SIZE 20

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

// Generator polynomials
static int generator_polynomial[ENCODER_n][K] = {
  { 1, 1, 1 },  { 1, 0, 1 }
};
//Some good generator polynomials
//{{ 1, 1, 1 },  { 1, 0, 1 },  K = 3
// { 1, 1, 0, 1 },  { 1, 1, 1, 0 },  K = 4
//  { 1, 1, 0, 1, 0 }, { 1, 1, 1, 0, 1 },  K = 5
//  { 1, 1, 0, 1, 0, 1 } { 1, 1, 1, 0, 1, 1 }}; K = 6
*/

#ifdef VITERBI_CONFIG_K3
  #define DATA_SIZE 8
  #define DATA_MAX 255
  #define MESSAGE_SIZE 20
  #define K 3
  #define m 2
  #define ENCODER_n 2
  #define NUMBER_OF_STATES 4
  static int generator_polynomial[ENCODER_n][K] = {
    { 1, 1, 1 },  { 1, 0, 1 }
  };
#endif
#ifdef VITERBI_CONFIG_K4
  #define DATA_SIZE 8
  #define DATA_MAX 255
  #define MESSAGE_SIZE 22
  #define K 4
  #define m 3
  #define ENCODER_n 2
  #define NUMBER_OF_STATES 4
  static int generator_polynomial[ENCODER_n][K] = {
    { 1, 1, 0, 1 },  { 1, 1, 1, 0 }
  };
#endif
#ifdef VITERBI_CONFIG_K5
  #define DATA_SIZE 8
  #define DATA_MAX 255
  #define MESSAGE_SIZE 24
  #define K 5
  #define m 4
  #define ENCODER_n 2
  #define NUMBER_OF_STATES 4
  static int generator_polynomial[ENCODER_n][K] = {
    { 1, 1, 0, 1 },  { 1, 1, 1, 0 }
  };
#endif
#ifdef VITERBI_CONFIG_K6
  #define DATA_SIZE 8
  #define DATA_MAX 255
  #define MESSAGE_SIZE 26
  #define K 6
  #define m 5
  #define ENCODER_n 2
  #define NUMBER_OF_STATES 4
  static int generator_polynomial[ENCODER_n][K] = {
    { 1, 1, 0, 1, 0, 1 }, { 1, 1, 1, 0, 1, 1 }
  };
#endif



#endif