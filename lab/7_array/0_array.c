#include<stdio.h>

int main(void){
	int vettore[5];
	vettore[0] = 1;
	vettore[1] = 2;
	vettore[2] = 3;
	vettore[3] = 4;
	vettore[4] = 5;

	for(int i=0; i < 5; i++)
		printf("%d ", vettore[i]);

	printf("\n");
	return 0;
}

