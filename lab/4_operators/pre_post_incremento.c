#include<stdio.h>

int main(void){

	int i = 0;
	int j = 0;

	int ii = i++; /* prima viene valutato i ( assegnato il suo valore ad ii )
		       * successivamente i viene incrementato di uno ma ii rimane
		       * al valore precedente di i, cioè 0
		       */

	int jj = ++j; /* prima j viene incrementato di uno e poi viene valutato il
		       * il suo valore (assegnato alla variabile jj). In questo ca
		       * jj vale 1
		       */

	printf("i=%d, ii=%d\n", i, ii);
	printf("j=%d, jj=%d\n", j, jj);
	return 0;	
}

