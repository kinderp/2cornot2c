#include<stdio.h>

int main(void){
	int i;	/* i non è inizializzata, è locale quindi avrà un valore sporco (casuale) */
	int *p;	/* anche  p  non è inizializzato,  punta ad una cella a caso, deve essere 
		 * inizializzato prima di essere usato con l'operatore di deferenziazione
		 * *p
		 */

	printf("i  = %d\n", i); /* non possiamo prevedere che valore stamperà */
	printf("&i = %p\n", &i);
	printf("p  = %p\n", p); /* cella  di memoria casuale forse appartenete
				 * ad un altro processo a cui non possiamo mai
				 * accedere
				 */
	printf("*p = %d\n", *p); /* accediamo ad una cella di memoria sconosciuta */
}
