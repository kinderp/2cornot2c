#include<stdio.h>

int main(void){
	short sx = -12345;
	unsigned short usx = sx; /* short: 16 bit,    UMax = 2^16 -1 = 65535
				  * per passare da valore signed ad unsigned 
				  * basta sommare Umax + 1 quindi:
				  * usx = -12345 + 65536 = 53191 
				  */
	
	int x = sx;		 /* int: 32 bit, verranno aggiunti 16 bit al
				  * la sequenza di 16 bit che rappresenta sx
				  * siccoma int è signed sarà effettuata una
				  * sign extension e non  una zero extension
				  * nei  sedici bit MSB aggiunti verrà copia
				  * to 1 e non 0 perchè sx era negativo ed è
				  * rappresentato  in complemento a due dove
				  * MSB è il bit di segno (0=+, 1=-)
				  * x = -12345 (ma con 32 e non 16 bi)
				  */

	unsigned ux = usx;	 /* usx è unsigned short,  aumentando  i bit 
				  * della sequenza da 16 a 32 (  con il cast 
				  * da  (unsigned short)  a  (unsigned) sarà
				  * effettuata una zero extension.
				  * ux = 53191 (ma con 32 e non 16 bit)
				  */
	printf("sx  = %d \t %#hx\n", sx, sx);
	printf("usx = %u \t %#hx\n", usx, usx);
	printf("x   = %d \t %#x\n", x, x);
	printf("ux  = %u \t %#x\n", ux, ux);
	return 0;
}
