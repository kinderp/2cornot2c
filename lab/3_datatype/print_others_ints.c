#include<stdio.h>

int main(void){
	unsigned int un = 300000000;
	short end = 200;
	long big = 65537;
	long long verybig = 12345678908642;
	/* Udasa un segnaposto errara nella printf() porta a
         * risultati strani */	
	printf("un  = %u  and not %d\n", un, un);
	printf("end = %hd and not %d\n", end, end);
	printf("big = %ld and not %hd\n", big, big);
	printf("verybig = %lld and not %ld\n", verybig, verybig);
	return 0;
}
