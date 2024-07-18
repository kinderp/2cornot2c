#include<stdio.h>

extern int count;

int accumulate(int number){
	printf("You call me %d times \n", count);
	static int subtotal;
	subtotal +=number;
	printf("Subtotal = %d\n", subtotal);
	return subtotal;
}
