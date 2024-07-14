#include <stdio.h>

int primo, secondo; /* variabili globali */

int somma();
int differenza();
int moltiplicazione();

int main(void){	
	int risultato; 	 // variabile locale
	char operazione; // variabile locale
	printf("Inserisci il primo operando\n");
	scanf("%d", &primo);
	printf("Inserisci il secondo operando\n");
	scanf("%d", &secondo);
	printf("s)Somma d)Differenza m)Moltiplicazine\n");
	scanf(" %c", &operazione);
	if (operazione == 's'){
		risultato = somma();
	} else if(operazione == 'd') {
		risultato = differenza();
	} else if(operazione == 'm') {
		risultato = moltiplicazione();
	} else {
		printf("Operazione non riconosciuta");
	}
	printf("Il risultato e': %d\n", risultato);
	return 0;
}

int somma(){
	return primo + secondo;
}

int differenza(){
	return primo - secondo;
}

int moltiplicazione(){
	return primo * secondo;
}
