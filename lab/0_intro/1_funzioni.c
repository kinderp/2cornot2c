#include<stdio.h>

int sottrazione(int, int);

int main(void){
	int minuendo = 10;
	int sottraendo = 3;
	int risultato = sottrazione(minuendo, sottraendo);
	printf("%d - %d = %d", minuendo, sottraendo, risultato);
}

int sottrazione(int minuendo, int sottraendo){
	return minuendo - sottraendo;
}
