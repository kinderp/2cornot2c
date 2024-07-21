/* 
 *  Puoi attivare il simbolo DEBUG in due modi:
 *  - 1 - Nel codice tramite direttiva #define
 *        #define DEBUG 1
 *  - 2 - A tempo di compilazione con -D a gcc
 *        gcc -DDEBUG=1 -o direttiva_if direttiva_if.c 
 *	  Nota: se hai già dichiarato il simbo
 *	        lo DEBUG nel codice tramite di
 *		rettiva #define non puoi usare
 *		il secondo metodo (-D con gcc)
 *		in quanto il compilarore dareb
 *		be errore di ridefinizione del
 *		simbolo DEBUG. 
 */

//#define DEBUG 0
#include<stdio.h>

int main(void){
	#if DEBUG
		printf("DEBUG is ON\n");
	#else
		printf("DEBUG is OFF\n");
	#endif /* DEBUG */
	return 0;
}
	
