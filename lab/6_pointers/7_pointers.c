#include<stdio.h>

#define N 300

int main(void){
	int a[N];
	for(int j=0; j < N; j++)
		a[j] = 1;
	int *p = NULL;
	int i = 0;
	p = a; // equivalente a: p = &a[0]

	/*
	 * array e puntatori sono simili:
	 * - posso usare aritmetica puntatori con nome array
	 * - posso usare indicizzazione array con puntatori
	 * quindi le espressioni di sotto sono tutte lecite
	 *   *(a + 1) // aritmetica puntatori con nome array
	 *   a[i]     // indicizzazione array con nome array
	 *   p[i]     // indicizzazione array con  puntatore
	 *   *(p +1)  // aritemetica puntatori con puntatore
	 */

	int risultato = 0;
	/* ciclo il vettore usando l'indicizzazione dei vettore sul nome del vettore */
	for(i = 0; i < N; i++)
		risultato += a[i];
	printf("%d\n", risultato);

	/* ciclo il vettore uando l'artmetica dei puntatori sul puntatore*/
	risultato = 0;
	for(p = a; p < &a[N]; p++)
		risultato += *p;
	printf("%d\n", risultato);

	/* ciclo il vettore usando l'aritmetica dei puntatori sul nome del vettore */
	risultato = 0;
	for(i=0; i < N; i++)
		risultato += *(a + i);		
	printf("%d\n", risultato);

	/* ciclo il vettore usando l'indicizzazione dei vettori sul puntatore */
	risultato = 0;
	p = a;
	for(i=0; i < N; i++)
		risultato += p[i];
	printf("%d\n", risultato);

	return 0;
}

