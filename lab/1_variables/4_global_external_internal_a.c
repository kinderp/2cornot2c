#include<stdio.h>  // printf()

int accumulate(int); /* prototipo di funzione definita in
		      * 4_global_external_internal_b.c
		      */

int count;  // variabile globale external linkage
	    // visibile in 4_global_external_internal_b.c

int main(void){
	int number;    // variabile locale non inizializzata
	int total = 0; // variabile locale inizializzata
	while(1){
		printf("Get me an integer > 0 (0 to quit)\n");
		scanf("%d", &number);
		++count;
		if(number == 0)
			break;
		total = accumulate(number);
	}
	printf("total=%d\n", total);
	return 0;
}
