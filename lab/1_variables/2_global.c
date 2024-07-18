#include<stdio.h>  // printf()

/* prototipi  funzioni che saranno 
 * successivamente definitea, dopo
 * il main()
 */
void one(void);
void two(void);
void three(void);

int global;	/* variabile globale: file scope, external  linkage
		 * static storage duration. E' visibile in tutto il
		 * file  da tutte le funzioni e  poenzialente negli
		 * altri file del programma. Automaticamente inizia
		 * lizzata a zero dal compilatore.
		 */

int main(void){
	printf("global=%d\n", global);
	one();
	two();
	three();
	return 0;

}

void one(void){
	global = global + 1;
	printf("global=%d\n", global);
}

void two(void){
	global = global + 1;
	printf("global=%d\n", global);
}

void three(void){
	global = global + 1;
	printf("global=%d\n", global);
}
