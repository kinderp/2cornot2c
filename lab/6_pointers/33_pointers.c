#include<stdio.h>

int main(void){
	int a = 1;
	int b = 2;
	int c = 3;

	int *ptr_a = &a;

	printf("a = %d\n", *ptr_a);
	printf("b = %d\n", *(ptr_a + 1));
	printf("a = %d\n", *(ptr_a + 2));

	return 0;
}
