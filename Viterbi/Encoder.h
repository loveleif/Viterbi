#ifndef VITERBI_ENCODER_H
#define VITERBI_ENCODER_H

#include "Config.h"
#include "Data.h"
#include "Util.h"
#include <stdio.h>

int output_table[NUMBER_OF_STATES][ENCODER_n];
Message encoding_table[DATA_MAX];

Message falt_encoder(Data data);
Message memory_falt_encoder(Data data);
void init_encoding_table();
void init_output_table();
#endif