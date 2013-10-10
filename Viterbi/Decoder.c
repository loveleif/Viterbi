#include "Decoder.h"
#include "Encoder.h"


Data viterbi_decoder(Message data) {
  int input[NUMBER_OF_STATES][NUMBER_OF_STATES]; /* maps current/nxt sts to input */
  int accum_err_metric[NUMBER_OF_STATES][2];
  int depth_of_trellis;
  int nextstate[NUMBER_OF_STATES][2]; /* for current st, gives nxt given input */
  int output[NUMBER_OF_STATES][2]; /* gives conv. encoder output */
  int next_state;
  int n, i, j;

  /* n is 2^1 = 2 for rate 1/2 */
  n = 2;
  
  depth_of_trellis = K * 5;

  /* initialize */
  for (i = 0; i < NUMBER_OF_STATES; ++i) {
    for (j = 0; j < NUMBER_OF_STATES; ++j)
      input[i][j] = 0;
    
    for (j = 0; j < n; j++) {
      nextstate[i][j] = 0;
      output[i][j] = 0;
    }

    accum_err_metric[i][0] = 0;
    accum_err_metric[i][1] = INT_MAX;
  }


}