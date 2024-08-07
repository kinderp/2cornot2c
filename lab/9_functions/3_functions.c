#include<stdio.h>
#define N 100

int sum(int a[], int dim);
int somma(int *, int dim);

int main(void){
	int vettore[N];
	for(int i=0; i < N; i++)
		vettore[i] = 1;

	printf("%d\n", sum(vettore, N));
	printf("%d\n", somma(vettore, N));
	return 0;	
}

int sum(int a[], int dim){
	int risultato = 0;
	for(int i=0; i < dim; i++)
		risultato += a[i];
	return risultato;
}

int somma(int *a, int dim){
	int risultato = 0;
	for(int i=0; i < dim; i++)
		risultato += a[i];
	return risultato;
}
