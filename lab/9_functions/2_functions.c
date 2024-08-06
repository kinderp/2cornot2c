#include<stdio.h>

int incrementa(int *, int); /* prototipo */

int main(void){
	int valore = 100;   /* valore iniziale di partenza */
	printf("valore = %d, &valore = %p\n\n", valore, &valore);

	printf("valore prima dell'invocazione: %d\n\n", valore);
	/* In questo passiamo l'indirizzo della variabile valore  e lo capiamo dentro
	 * una  variabile puntatore ad intero locale alla funzione  ( primo parametro
	 * in  ingresso della funzione incrementa). Dentro la funzione dereferenziamo
	 * il puntatore accedendo effettivamente alla locazione di memoria della vari
	 * abile valore del chiamante modificando di fatto il valore originale.  
	 */
	int risultato = incrementa(&valore, 3); /* incremento il valore di iniziale di 3 */
	printf("\n");
	printf("valore dopo     l'invocazione: %d\n", valore);
	printf("risultato                    : %d\n", risultato);
}

int incrementa(int *valore_f, int iterazioni){
	printf("************incrementa****************\n");
	for(int i=0; i<iterazioni; i++){
		(*valore_f)++;
		printf("i=%d valore_f = %d, &valore_f = %p\n", i, *valore_f, valore_f);
	}
	printf("************incrementa****************\n");
	return *valore_f; /* superfluo */
}

