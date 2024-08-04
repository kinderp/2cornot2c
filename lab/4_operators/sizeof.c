#include<stdio.h>

int main(void){
	int n = 0;
	size_t int_in_byte;

	int_in_byte = sizeof(int);
	printf("n = %d, n occupa %zd bytes\n", n, sizeof n);
	printf("Gli interi occupano %zd bytes\n", int_in_byte);
	return 0;
}
