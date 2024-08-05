#include<stdio.h>

int main(void){
	int *p = NULL; /* inizializzo il puntatore p a NULL */
	if (p != NULL)	/* prima di deferenziare controllo se p è diverso da NULL */
		printf("*p = %d", *p);

}
