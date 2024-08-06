#include<stdio.h>

#define NUM_ELEM 100
int main(void){
	int array[NUM_ELEM] = {0};

	unsigned int num_byte_array = sizeof(array); /* n. di byte occupati dall'intero verrore (100*4) */
	unsigned int num_byte_int   = sizeof(int);   /* n. di byte occupati da un intero in questa arch */

	unsigned int n_elem = num_byte_array / num_byte_int;
	printf("Il vettore di interi occupa %d byte\n", num_byte_array);
	printf("Un singolo intero occupa %d byte\n", num_byte_int);
	printf("Il vettore ha %d(byte)/%d(byte) = %d elementi\n", num_byte_array, num_byte_int, num_byte_array/num_byte_int);
	return 0;
}

