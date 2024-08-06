#include<stdio.h>

int incrementa(int, int); /* prototipo */

int main(void){
	int valore = 100;   /* valore iniziale di partenza */
	printf("valore = %d, &valore = %p\n\n", valore, &valore);

	printf("valore prima dell'invocazione: %d\n\n", valore);
	/* quando la funzoine incremanta() viene invocata, il contenuto della variabile di nome valore
	 * viene copiato all'interno della variabile valore_f ( primo parametro in input nel prototipo
	 * della funzione). Il valore contenuto in questa nuova variabile puo' essere modificato ma è
	 * una copia del valore della variabile orginale nel chiamante. Quest'ultimo dunque non subisce
         * alcuna variazione perchè si trova in un'altra variabile in memoria.
	 */
	int risultato = incrementa(valore, 3); /* incremento il valore di iniziale di 3 */
	printf("\n");
	printf("valore dopo     l'invocazione: %d\n", valore);
	printf("risultato                    : %d\n", risultato);
}

int incrementa(int valore_f, int iterazioni){
	printf("************incrementa****************\n");
	for(int i=0; i<iterazioni; i++){
		valore_f++;
		printf("i=%d valore_f = %d, &valore_f = %p\n", i, valore_f, &valore_f);
	}
	printf("************incrementa****************\n");
	return valore_f;
}

