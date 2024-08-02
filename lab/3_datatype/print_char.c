#include<stdio.h>

int main(void){
	char lettera_a = 'A';
	printf("%c\n", lettera_a);  /* stampa il carattere A */
	printf("%d\n", lettera_a);  /* stampa il valore intero usato per codificare il carattere A */ 
	printf("%u\n", lettera_a);  /* stampa il valore senza segno, dovrebbe essere lo stesso */
	printf("%#x\n", lettera_a); /* stampa la rappresentazione esadecimale */
}
