#include<stdio.h>

int main(void){
	char scelta;
	int a, b, c, other;
	printf("a=%d \t b=%d \t c=%d \t other=%d\n", a, b, c, other);
	printf("Quale variabile vuoi incrementare?\n");
	printf("[a-A]\t[b-B]\t[c-C]\n");
	scanf(" %c", &scelta);
	switch(scelta){
		case 'a':
		case 'A':
			a++;
			break;
		case 'b':
		case 'B':
			b++;
			break;
		case 'c':
		case 'C':
			c++;
			break;
		default:
			other++;
			/* non ho bisogno del break perchè è l'ultimo case se lo avessi messo sopra dovevo mettere il break altrimenti
			 * l'esecuzione  del  flusso  sarebbe  passata  al  codice  relativo  al  case sottostante la clausola default
			 */
	}
	printf("a=%d \t b=%d \t c=%d \t other=%d\n", a, b, c, other);
	return 0;
}

