#include<stdio.h>

void call_me(void); /* prototipo di funzione  necessario perchè la
		     * chiamata alla funzione call_me() è eseguita
		     * prima della sua definizione.
		     */

int main(void){
	/*  call_me() incrementa di uno una variabile automatica statica
	 *  (count) ed una variabile automatica (bad_count). Entrambe so
	 *  no variabili locali al corpo dellla funzione ma  count viene
	 *  allocata all'inizio del progrmma e deallocata alla fine (sta
	 *  tic storage duration)  quindi conserva il  valore precedente 
	 *  tra una chiamata e la successiva della funzione call_me();la
	 *  variabile count raggiunge un valore pari al  numero di volte
	 *  che il chiamante richiamerà la funzione call_me().
	 *  La variabile non statica  bad_count viene ogni  volta che si 
	 *  entra nel blocco della funzione allocata e poi deallocata al
	 *  al termine del blocco ed infatti varrà al massimo uno.
	 */
	call_me();
	call_me();
	call_me();
	call_me();
	call_me();

}

void call_me(void){
	static int count; /* variabile automatica statica: automatic scope,
			   * no linkage, static storage duration. Le varia
			   * bili statiche sono inizializzata a zero impli
			   * citamente e hanno un tempo di vita pari a quel
			   * lo del programma
			   */
	int bad_count = 0;

	count = count + 1;
	bad_count = bad_count + 1;

	printf("count=%d \t &count=%p\n", count, &count);
	printf("bad_count=%d \t &bad_coubt=%p\n", bad_count, &bad_count);

	printf("You call me %d times\n", count);
	printf("\n");
}
