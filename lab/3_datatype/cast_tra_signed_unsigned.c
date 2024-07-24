#include<stdio.h>
/*
 * Usiamo la rappresentazione in complemento a due del valore 27
 * che abbiamo calcolato nell'esercizio precedente e che è: 0xE5
 * 
 * shoirt int v = -27
 * è un numero con segno (complento a due) ma short (16 bit) la
 * rappresentazione in esadecimale (complemento a 2) è: 0xff-ff
 * ff-E5 
 * 
 * Cosa accade se facciamo un cast da unsigned a signed? Per se
 * mplicita stiamo consideriamo short int per avere solo 16 bit.
 *
 *  0XFF-FF-FF-E5 in binario è:
 *  +---+---+---+---+---+---+---+---+
 *  | 1 | 1 | 1 | 0 | 0 | 1 | 0 | 1 |
 *  +---+---+---+---+---+---+---+---+
 *
 * Castando il tipo (short int) al tipo (unsigned int) la rap-
 * presentazione (la seuqenza di bit)  rimarrà la stessa ma l'
 * interpretazione  che il  sistema darà  ai bit sarà diversa.
 * Nel caso di (short int) sarà interpretato in complemento a
 * due, nel caso di  (unsigned int) come una sequenza binaria
 * il cui valore è:
 *
 *  +---+---+---+---+---+---+---+---+
 *  | 1 | 1 | 1 | 0 | 0 | 1 | 0 | 1 |
 *  +---+---+---+---+---+---+---+---+
 *  128 + 64+ 32+         4     + 1 = 229
 *
 *  Gli altri 8 bit  (dal 15-esimo all'ottavo) sono tutti a uno
 *  otto bit ad uno (0xff) 255 shiftati di otto 255*(2^8)=65280
 *  65280+229 = 65509
 *  Mi aspetto che il sistema a seguito del cast stamperà 65509
 */
int main(void){
	short int v = -27;
	unsigned int u_v = (unsigned short) v;
	printf("v = %d,  u_v = %u\n", v, u_v);   /* mi aspetto 0xFF-E5 */
	printf("v = %#x, u_v = %#x\n", v, u_v);  /* mi aspetto sempre 0xff-e5 ma valore decimale 65509 */
	return 0;
}
