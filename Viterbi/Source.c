#include "Source.h"

/* return a random number between 0 and limit inclusive. */
int rand_lim(int limit) {
    int divisor = RAND_MAX/(limit+1);
    int retval;

    do { 
        retval = rand() / divisor;
    } while (retval > limit);

    return retval;
}

Data rand_data() {
	return rand_lim(0xFF);
}