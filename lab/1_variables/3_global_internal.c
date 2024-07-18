#include<stdio.h>

void one(void);
void two(void);

static int global_internal; /* variabile globale ma con internal linkage
			     * cioè è visibile solo a tutte le funzioni
			     * del file corrente e non in altri file se
			     * ci fossero.
			     */

int main(void){
	printf("global_internal=%d\n", global_internal);
	one();
	two();
}

void one(void){
	global_internal++;
	printf("global_internal=%d\n", global_internal);
}

void two(void){
	global_internal++;
	printf("global_internal=%d\n", global_internal);
}
