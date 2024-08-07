#include<stdio.h>

#define N_RIGHE 6
#define N_COLONNE 7

int main(void){
	int mat[N_RIGHE][N_COLONNE];

	int i; // indice riga
	int j; // indice colonna
	for(i=0; i<N_RIGHE; i++)
		for(j=0; j<N_COLONNE; j++)
			mat[i][j] = (i*N_COLONNE) + j;
	
	for(i=0; i<N_RIGHE; i++){
		for(j=0; j<N_COLONNE; j++)
			printf("%2d ", mat[i][j]);
		printf("\n");
	}

	printf("\n");
	/* Gli elementi della matrice sono  contigui in memoria e 
	 * posso accedervi senza la notazione  ad indici del vett
	 * ore ma usando l' artimetica dei  puntatori, se i e' l'
	 * indice di riga  e j l' indice  colonna per accedere al
	 * k-esimo elemento contigue in  memoria  basta  usare la
	 * formula k = (i*N_COLONNE) + j 
	 * Per accedere ad esempio all' ultimo  elemento della 3°
	 * riga: k = 20, i=2 (3° riga), j=6 (7° colonna) (ricorda
	 * che gli indici partono da 0) k=2*7+6=20 
	 */
	for(i=0; i<N_RIGHE; i++)
		for(j=0; j<N_COLONNE; j++)
			printf("%d ", *(*mat + ( (i*N_COLONNE) + j) ) );
	printf("\n");
	return 0;
}
