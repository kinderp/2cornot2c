#include<stdio.h>

int somma(int, int);
int differenza(int, int);
int moltiplicazione(int, int);

int main(void){
	int risultato = 0;
	int primo, secondo;
	char operazione;

	printf("Inserisci il primo operando\n");
	scanf("%d", &primo);
	printf("Insesci il secondo operando\n");
	scanf("%d", &secondo);
	printf("s)Somma d)Differenza m)Moltiplicazione\n");
	getchar();
	operazione = getchar();
	switch(operazione){
		case 's':
			risultato = somma(primo, secondo);
			break;
		case 'd':
			risultato = differenza(primo, secondo);
			break;
		case 'm':
			risultato = moltiplicazione(primo, secondo);
			break;
		default:
			printf("Operazione non riconosciuta\n");

	}
	printf("Il risultato e': %d\n", risultato);	
	return 0;
}

int somma(int primo_addendo, int secondo_addendo){
	return primo_addendo + secondo_addendo;
}

int differenza(int minuendo, int sottraendo){
	return minuendo - sottraendo;
}

int moltiplicazione(int primo_fattore, int secondo_fattore){
	return primo_fattore * secondo_fattore;
}
