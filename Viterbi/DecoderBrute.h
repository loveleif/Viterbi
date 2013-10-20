#ifndef VITERBI_BRUTEDECODER_H
#define VITERBI_BRUTEDECODER_H

#include "Data.h"
#include "Encoder.h"
#include "Util.h"

Data brute_force_viterbi_decoder(Message encoded_message);
int hamdist(int x, int y);

#endif