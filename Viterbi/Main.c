#include<stdio.h>
#include "Source.h"
#include "Encoder.h"

int main() {
	printf("%x -> %x\n", 0, falt_encoder(0));
	printf("%x -> %x\n", 1, falt_encoder(1));
	printf("%x -> %x\n", 2, falt_encoder(2));
	printf("%x -> %x\n", 3, falt_encoder(3));
	printf("%x -> %x\n", 4, falt_encoder(4));
	printf("%x -> %x\n", 5, falt_encoder(5));
	printf("%x -> %x\n", 6, falt_encoder(6));

	printf("\n");
	return 0;
}