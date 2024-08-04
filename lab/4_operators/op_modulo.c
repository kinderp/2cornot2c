#include<stdio.h>

int main(void){
	int n;
	printf("Inserisci un numero tra 1 e 10\n");
	scanf("%d", &n);
	int pari_o_dispari = n % 2;
	if(pari_o_dispari == 0){
		printf("%d e' pari\n", n);
	} else{
		printf("%d e' dispari\n", n);
	}
	return 0;
}
