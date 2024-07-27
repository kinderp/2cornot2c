#include<stdio.h>
/*
 * Anche nel  caso di cast  da unsigned a signed
 * la sequenza di bit rimane invariata ma cambia
 * solo l'interpretazione data alla sequenza.
 * Scegliendo  come valore senza segno l'estremo
 * superiore  della  rappresentazione (UMax) che
 * nel caso di  (unsigned short) e' 65536 (2^16)
 * per conoscere  il valore  con segno basta sot
 * trarre (UMax + 1) o 2^W 
 */

int main(void){
	unsigned short u = 65535; /* UMax */
	short int tu = (short int) u;
	printf("u = %u, tu=%d\n", u, tu);
	printf("u = %#x, tu=%#x\n", u, tu);
	return 0;
}
