#include<stdio.h>

int main(void){
	int i = 42, j = 107;
	printf("i = %d, &i = %p\n", i, &i);
	printf("j = %d, &j = %p\n", j, &j);
	getchar();
	int *p = &i;
	int *q = &j;
	printf("*p = %d, p = %p\n", *p, p);
	printf("*q = %d, p = %p\n", *q, q);
}
