#include<stdio.h>

int main(void){
	char *mesi_anno[12] = {"Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno", "Luglio",
			      "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"};

	int mese;
	printf("Inserisci un numero da 1 a 12\n");
	scanf("%d", &mese);

	printf("%d -> %s\n", mese, mesi_anno[mese-1]);
	return 0;
}
