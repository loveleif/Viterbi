#include "Decoder.h"


Data viterbi_decoder(Message data) {
  int input[NUMBER_OF_STATES][NUMBER_OF_STATES]; /* maps current/nxt sts to input */
  int accum_err_metric[NUMBER_OF_STATES][2];
  int depth_of_trellis;
  int nextstate[NUMBER_OF_STATES][2]; /* for current st, gives nxt given input */
  int output[NUMBER_OF_STATES][2]; /* gives conv. encoder output */
  int next_state;
  int branch_output[2];                     /* vector to store trial enc output */
  int n, i, j, state, in;
  int recieved, current_state;
  /* n is 2^1 = 2 for rate 1/2 */
  n = 2;
  
  depth_of_trellis = K * 5;

  current_state = 0; 
  for (i = 0; i < MESSAGE_SIZE; i += m) {
    recieved = (data >> i) & 3; // Todo, change 3 (binary ...0011)
    printf("%s ", byte_to_binary(recieved, 2));

    
  }

  /* initialize 
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

  for (state = 0; state < NUMBER_OF_STATES; ++state) { // State
    for (in = 0; in < n; ++in) { // Input
      next_state = next_state_table[state][in];
      input[in][next_state] = 1;
    }
  }
  */

  return 0;
}