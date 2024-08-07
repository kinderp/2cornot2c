#include<stdio.h>
#include<string.h>

int main(void){
	char ciao[] = "ciao";
	/*  Il nome di un array e' un putatore costante al primo elemento del vettore
	 *  non posso farlo puntatore ad un'altro indirizzo, si ottiene un errore:
	 *  error: assignment to expression with array type
	 */
	//ciao = "miao";/* errore: ciao e' puntaore costante */
	
	/* Il puntatore non può essere modificato ma i caratteri ovviamente si come 
	 * singoli elementi del vettore oppure usando la strcpy()
	 */
	ciao[0] = 'm'; // corretto
	printf("%s\n", ciao); // (1) miao
	strcpy(ciao, "ciao"); 
	printf("%s\n", ciao); // (2) ciao

	printf("\n");

	/* Se assegno la stringa ad un puntatore a carattere posso far puntare ciao_
	 * ad un' altra  cella di memoria senza problemi perche' il puntatore non e' 
	 * const
	 */
	char *ciao_ = "ciao";
	printf("%s\n", ciao_); // (3) ciao
	ciao_ = "miao";
	printf("%s\n", ciao_); // (4) miao
	/* In questo caso *ciao_ punta alla stringa "ciao" e di solito il compilatore 
	 * inserisce le stringhe in un'area di memoria a sola lettura quindi probabil
	 * mente tentare di modificare la stringa con indicizzazione  o strcpy  porta 
	 * al crash del programma (segmentation fault)
	 */
	strcpy(ciao_, "ciao");
	printf("%s\n", ciao_); // (5) ciao
	ciao_[0] = 's';
	printf("%s\n", ciao_); // (6) siao
	
}
