#include<stdio.h>

int main(void){
	int vettore[5];

	/* inizializzo gli elementi del vettore con un ciclo */	
        for(int i=0; i < 5; i++)
                vettore[i] = i;

	/* accedo agli elementi del vettore tramite [] */
        for(int i=0; i < 5; i++)
                printf("%d ", vettore[i]);
	printf("\n");

	/* accedo agli elementi del vettore tramite aritemetica puntatori */
        for(int j=0; j < 5; j++)
                printf("%d ", *(vettore + j));
	printf("\n");
	
}

