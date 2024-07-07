/*
 * 0_intro -- Primo esempio di programma in c
 *
 * Cosa imparerai:
 *	*) Cosa sono gli header files
 *      *) Concetto di funzione e chiamata di funzione
 *	*) Processo di creazione di un file eseguibile (binario)
 *
 * Utilizzo:
 *      gcc -o bin/0_hello 0_hello.c
 *      bin/0_hello	      
 */

#include <stdio.h>

int main(void){
	printf("Hello World\n");
	return 0;
}
