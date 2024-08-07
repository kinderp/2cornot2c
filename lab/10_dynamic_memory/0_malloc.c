#include<stdio.h>
#include<stdlib.h>

#define N 10

int main(void){
	/* allocazione statica a tempo di compilazione, la dimensione del vettore
	 * deve essere nota a tempo di compilazione e non puo' essere modificata
	 * successivamente durante l'esecuzione del programma.
	 */
	int statico[N];
	for(int i=0; i<N; i++)
		statico[i] = i;

	/* allocazione dinamica a tempo di esecuzione, possiamo definire la dimen
	 * sione del vettore a durante l'esecuzione del programma ad esempio chie
	 * dendo all'utente il numero di elementi del vettore
	 */
	int M = 0;
	printf("Quanti elementi per il vettore?\n");
	scanf("%d", &M);
	/* malloc alloca n byte contigui in memoria e ritorna l'indirizzo del primo
	 * byte relativo allo spazio allocato.Nota come la variabile dinamico e' un
	 * puntaore ma nel ciclo posso usare l'indicizzazione come fosse un vettore
	 */
	int *dinamico = (int *) malloc(M * sizeof(int));
	/* dinamico e' un puntatore*/
	for(int j=0; j<M; j++)
		dinamico[j] = j;

	int k;
	printf("statico : ");
	for(k=0; k<N; k++)
		printf("%d ", statico[k]);
	printf("\n");

	printf("dinamico: ");
	for(k=0; k<M; k++)
		printf("%d ", dinamico[k]);
	printf("\n");
	/* dealloco la memoria con free() */
	free(dinamico);
	return 0;
}
