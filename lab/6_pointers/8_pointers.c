#include<stdio.h>

int main(void){
	int a[2], *p, *q;
	printf("(int  ) %ld bytes\n", sizeof(int));
	printf("(long ) %ld bytes\n", sizeof(long));
	printf("(int *) %ld bytes\n", sizeof(int *));
	printf("\n");

	/* La differenza  tra due puntatori ritorna  il numero di elementi
         * che li separa e NON il numero di byte  come ci si  aspetterebbe 
         * devi fare  un  cast  per  ottenere  il risultato atteso
	 */
	p = a;
	q = a + 1; // equivalente a: q = p + 1, q = &a[1]
	printf("%ld\n", q - p); // %ld -> long int, un puntatore è di tipo long int (arch a 64 bit)
	printf("%ld\n", (long)q - (long)p);
	printf("\n");

	/* questi vale anche se le variabili puntate non sono elementi di un array */
	int b = 2;
	int c = 1;
	int d = 3;
	q = &d;
	p = &b;
	printf("&b = %p\n", p);
	printf("&c = %p\n", &c);
	printf("&d = %p\n", q);
	printf("%ld\n", q - p); // distanza in elementi in memoria
	printf("%ld\n", (long)q - (long)p); // distanza in termini di byte
}
