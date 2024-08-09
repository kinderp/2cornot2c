#include<stdio.h>

/* dichiaro il nuovo tipo che si chiama: struct punto_2d */
struct punto_2d {
	int x;
	int y;
};

int main(void){
	/* dichiaro una variabile ed un puntatore del tipo struct punto_2d
	 * fai attenzione che il nuovo tipo è "struct punto_2s" e non sola
	 * mente "punto_2d", non ti scordare "struct" nel nome del tipo.
	 */
	struct punto_2d i;
	struct punto_2d *ptr = NULL; /* alloco spazio per il puntatore */
	
	/* il puntaore deve essere inizializzato all'indirizzo della struttura
	 * altrimenti non punta ad una locazione di memoria valida per noi
	 */
	ptr = &i;
	/* inizializzo la struttura accedendo ai campi con la notazione puntata
	  * attraverso una variabile di tipo "struct punto_2d"
	  */
	i.x = 0;
	i.y = 0;
	printf("(%d, %d)\n", i.x, i.y);
	
	/* accedo ai campi della struttura attraverso il puntatore usando -> */
	ptr->x = 1;
	ptr->y = 1;
	printf("(%d, %d)\n", ptr->x, ptr->y);

	return 0;
}
