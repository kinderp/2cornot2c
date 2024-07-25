#include<stdio.h>

/*
 * Calcoliamo la rappresentazione binaria del valore 27:
 *
 *  valore	 resto
 *	27 | 2 | 1
 *	13 | 2 | 1
 *	 6 | 2 | 0
 *	 3 | 2 | 1
 *	 1 | 2 | 1
 *	 0 | 
 *
 *    7   6   5   4   3   2   1   0
 *  +---+---+---+---+---+---+---+---+
 *  | 0 | 0 | 0 | 1 | 1 | 0 | 1 | 1 |
 *  +---+---+---+---+---+---+---+---+
 *  		 16 + 8 +   + 2 + 1 = 27
 *
 *  Calcoliamo la rappresentazione esadecimale del valore 27:
 *  0001 1011
 *  \  / \  /
 *    1    B
 *
 * Gli interi unsigned sono rappresentati in questo modo. Stam 
 * pando il valore 27 (unsigned int) in esacimale con printf()
 * dobbiamo ottenere la sequenza: 0x1B
 *
 * Per gli interi con segno si usa la rappresentazione in comp
 * lemento a due, per trovare la sequenza di bit del valore ne
 * gativo dobbbiamo calcolare il complemento a 2 del valore po
 * sitivo ( nega tutti i bit ed aggiungi uno)
 *
 * unsigned: 00011011
 * negato  : 11100100
 * negato+1: 11100101
 *
 * 1110 0101
 * \  / \  /
 *   E    5
 *
 * Gli interi su questa architettura sono a 32  bit ( 4 byte )
 * Per gli altri byte estendiamo il bit di segno (MSB) del pri
 * mo byte
 *
 * 00000000 00000000 00000000 00011011
 * 11111111 11111111 11111111 11100101
 *
 */

int main(void){
	int positive = 27;
	int negative = -27;
	unsigned u_positive = 27;

	/* 
	 * stamperemo gli interi in esadecimale (base 16) per
	 * verificare la diversa rappresentazione degli interi
	 * di tipo signed ed unsigned
	 */
	printf("signed positive: %#x\n", positive);    /* mi aspetto 0x00-00-00-1B */
	printf("signed negative: %#x\n", negative);    /* mi aspetto 0xff-ff-ff-E5 */
	printf("       unsigned: %#x\n", u_positive);

	return 0;
}
