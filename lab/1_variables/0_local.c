#include<stdio.h>

void print_var(void);

int main(void){
	
	print_var();
	print_var();
	print_var();
}

void print_var(void){
	int local_var; /* variabile locale (class auto: block scope, auto
			* storage duration, no linkage) non inizializzata
			* conterrà un vaore casuale, indefinito. Le varia
			* bili locali devono essere inizializzate esplici
			* tamente.
			*/

	int initialized_local_var = 0;

	printf("local_var=%d \t\t &local_var=%p\n", local_var, &local_var);
	printf("init_local_var=%d \t &init_local_var=%p\n", initialized_local_var, &initialized_local_var);
	printf("\n");
}

