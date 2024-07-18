#include<stdio.h>

void call_me(void);

int main(void){
	call_me();
	call_me();
	call_me();
	call_me();
	call_me();

}

void call_me(void){
	static int count; /* variabile automatica statica: automatic scope,
			   * no linkage, static storage duration. Le varia
			   * bili statiche sono inizializzata a zero impli
			   * citamente e hanno un tempo di vita pari a quel
			   * lo del programma
			   */
	int bad_count = 0;

	count = count + 1;
	bad_count = bad_count + 1;

	printf("count=%d \t &count=%p\n", count, &count);
	printf("bad_count=%d \t &bad_coubt=%p\n", bad_count, &bad_count);

	printf("You call me %d times\n", count);
	printf("\n");
}
