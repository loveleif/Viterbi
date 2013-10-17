#ifndef VITERBI_DECODER_H
#define VITERBI_DECODER_H

#include <limits.h>
#include "Data.h"
#include "Encoder.h"
#include "Util.h"
#include <math.h>

Data viterbi_decoder(Message encoded_message);

#endif