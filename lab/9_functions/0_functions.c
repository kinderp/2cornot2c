#include<stdio.h>

#define ESPONENTE 16

int potenza_di_due(int esponente); /* prototipo o dichiarazione di funzione */

int main(void){
	/* stampo potenze del 2 con esponente da 0 a 16 */
	for(int i=0; i < ESPONENTE + 1; i++){
		int risultato = potenza_di_due(i); /* invocazione funzione */
		printf("2^(%d)\t = %d\n", i, risultato);
	}
	return 0;

}

/* definizione di funzione */
int potenza_di_due(int esponente){
	int risultato = 1;
	for(int i=1; i <= esponente; i++)
		risultato *= 2;
	return risultato;
}

