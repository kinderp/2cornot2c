/*
 * Puoi definire DEBUG in due modi
 * - 1 - Nel codice: #define DEBUG
 * - 2 - con gcc   : gcc -DDEBUG -o direttiva_ifdef direttiva_ifdef.c
 * Nota: puoi anche eliminare la 
 *       definizione del simbolo
 *	 DEBUG nel codice usando
 *	 #undef DEBUG
 *	 Questo annullerra DEBUG
 *	 anche se hai usato il 2
 *	 metodo
 */

//#undef DEBUG
#include<stdio.h>

int main(void){
	#ifdef DEBUG
		printf("DEBUG is defined\n");
	#else
		printf("DEBUG is not defined\n");
	#endif /* DEBUG */
	return 0;
}
