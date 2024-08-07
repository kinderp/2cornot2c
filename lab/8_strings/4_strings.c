#include<stdio.h>

int main(void){
	char ciao_v1[5] = "ciao"; // vettore dimensione fissa (+1 per '\0')
        char *ciao_v2 = "ciao";   // puntatore a carattere
	char ciao_v3[] = "ciao";  // vettore dimensine dedotta dal numero di caratteri
	
	printf("%s\n", ciao_v1);
	printf("%s\n", ciao_v2);
	printf("%s\n", ciao_v3);
	printf("%s\n", "ciao");
	return 0;
}

