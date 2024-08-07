#include<stdio.h>

void leggi(const char *);

int main(void){
	char qualcosa[30] = "Non voglio essere modificata";
	qualcosa[0] = 'x';
	qualcosa[1] = 'x';
	qualcosa[2] = 'x'; 
	leggi(qualcosa);
}

void leggi(const char *qualcosa){
	// qualcosa[0] = '\0'; 
	/* Se decommenti la riga sopra e provi a ricompilare ottineni errore 
	 * error: assignment of read-only location *qualcosa
	 * perchè stai provando a modificare una locazione di memoria in sola
	 * lettura (puntatore costante)
	 */ 			
	printf("%s\n",qualcosa);
}
