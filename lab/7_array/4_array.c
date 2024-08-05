#include<stdio.h>

#define N 5

int main(void){
	int vettore[N] = {0, 1, 2, 3, 4};

        for(int i=0; i < N; i++)
                printf("%d\t\t\t", vettore[i]);
        printf("\n");

	for(int j=0; j < N; j++)
		printf("%p\t\t", vettore + j);
        printf("\n");

        return 0;
}
