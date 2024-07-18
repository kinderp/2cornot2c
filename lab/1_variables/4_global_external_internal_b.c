#include<stdio.h>

extern int count; /* dichiarazione di variabile esterna
		   * definita in 4_global_external_internal_a.c
		   * per  vedere la variabile in questo file la
		   * dichiarazione è necessaria.
		   */

int accumulate(int number){
	printf("You call me %d times \n", count);
	static int subtotal; /* variabile locale statica, ricorda il valore
			      * tra una chiamata e la successiva della funz
			      * ione accumulate()
			      */
	subtotal +=number;
	printf("Subtotal = %d\n", subtotal);
	return subtotal;
}
