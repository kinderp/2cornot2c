#include<stdio.h>  // printf()
#include<stdlib.h> // malloc(), free()
#include<string.h> // strcpy()

int main(void){
        char *array_di_puntatori[12] = {"Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno", "Luglio",
                              		"Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"};

	char matrice[12][10] =  {"Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno", "Luglio",
                              	 "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"};

	/* array di puntatore a char allocato dinamicamente */
	char **matrice_dinamica = (char **) malloc(12*sizeof(char*)); // alloca spazio contiguo per 12 puntatori a char
        for(int k=0; k<12; k++)
		matrice_dinamica[k] = (char *)malloc(10*sizeof(char));   // alloca spazio contiguoper 10 caretteri

	/* Ho allocato spazio per 10 caratteri per tutti i mesi e sto sprecando spazio ma nulla mi impedisce di allocare
	 * il numero di caratteri strettamente necessario per ogni singolo mese, non avevo voglia di perdere tempo ma e'
	 * una cosa fattibile ovviamente ed avremmo avuto lo stesso risultato degli array di puntatori solo che l'alloca
	 * zione in questo caso è dinamica cioe' e' avvenuto a tempo di esecuzione e non statico cioe' a tempo di compil
	 * azione. Usa l'allocazione dinamica solo quando la dimensine del vettore o della matrice non e' nota se non du
	 * rante l'esecuzione; in questo caso e' inutile usare l'allocazione dinamica perche' sia la dimensione delle ri
	 * ghe che delle colonne e' nota prima dell'esecuzione.
	 */

	/* Questo metodo per inizializzare i vettori di caratteri non va bene se
	 * e' prevista la deallocazione con free() in quanto gli string literals
	 * sono allocati nel DATA segment che e' a sola lettura quindi non potra
	 * nno e non dovranno mai essere deallocate, provare a fare una free() su
	 * queste variabili e' inutile (non stanno nello stack) e porta ad un seg
	 * mentation fault in quanto free() provera' ad scrivere in memoria a so
	 * la lettura
	 */

	/* decommanta le righe di sotto e commaenta le righe con strcpy() per pro
	 * vare l'errore di segmentation fault spiegato sopra
	 */

	/*
	matrice_dinamica[0]  = "Gennaio";
	matrice_dinamica[1]  = "Febbraio";
	matrice_dinamica[2]  = "Marzo";
	matrice_dinamica[3]  = "Aprile";
	matrice_dinamica[4]  = "Maggio";
	matrice_dinamica[5]  = "Giugno";
	matrice_dinamica[6]  = "Luglio";
	matrice_dinamica[7]  = "Agosto";
	matrice_dinamica[8]  = "Settembre";
	matrice_dinamica[9]  = "Ottobre";
	matrice_dinamica[10] = "Novembre";
	matrice_dinamica[11] = "Dicembre";
	*/
		
	strcpy(matrice_dinamica[0] , "Gennaio");
	strcpy(matrice_dinamica[1] , "Febbraio");
	strcpy(matrice_dinamica[2] , "Marzo");
	strcpy(matrice_dinamica[3] , "Aprile");
	strcpy(matrice_dinamica[4] , "Maggio");
	strcpy(matrice_dinamica[5] , "Giugno");
	strcpy(matrice_dinamica[6] , "Luglio");
	strcpy(matrice_dinamica[7] , "Agosto");
	strcpy(matrice_dinamica[8] , "Settembre");
	strcpy(matrice_dinamica[9] , "Ottobre");
	strcpy(matrice_dinamica[10], "Novembre");
	strcpy(matrice_dinamica[11], "Dicembre");

	int mese;
        printf("Inserisci un numero da 1 a 12\n");
        scanf("%d", &mese);

        printf("%d -> %s\n", mese, array_di_puntatori[mese-1]);
        printf("%d -> %s\n", mese, matrice[mese-1]);
        printf("%d -> %s\n", mese, matrice_dinamica[mese-1]);
	
	/* con l'allocazione dinamica e' compito del programmatore deallocare la memoria quando non serve piu'*/
		
	/* prima dealloco i 12 array di caratteri di lunghezza 10 contenenti i mesi */
	for(int k=0; k<12; k++)
		free(matrice_dinamica[k]);
	/* infine dealloco i 12 puntatori a caratteri che puntavano ai 12 vettori di caratteri prima deallocati */
	free(matrice_dinamica);
        return 0;
}
