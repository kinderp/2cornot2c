
#include<stdio.h>

int main(void){
	int stipendio_base = 1000;
	int stipendio_medio = 3000;
	int stipendio_alto = 5000;

	int eta;
	char laurea = 0;
	printf("Inserisci la tua eta'\n");
	scanf("%d", &eta);
	printf("Hai la laurea?\n");
	printf("[S]ì \t [N]o\n");
	scanf(" %c", &laurea);
	if(laurea == 'S' || laurea == 'N') {
		if(eta < 30){
			printf("Sei giovane, il tuo stipendio e' %d\n", stipendio_base);
		} else if (eta > 30 && eta < 50 && laurea == 'N'){
			printf("Non hai la laurea, il tuo stipendio e' %d\n", stipendio_base);
		} else if (eta > 30 && eta < 50 && laurea == 'S'){
			printf("Hai la laurea, il tuo stipendio e' %d\n", stipendio_medio);
		} else {
			printf("Hai esperienza, il tuo stipendio e' %d\n", stipendio_alto);
		}
	} else {
		printf("Digita S per sì o N per no\n");
		return 1;
	}
	return 0;
}
