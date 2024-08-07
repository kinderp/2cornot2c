#define N 300

int main(void){
	int a[N] = {1};
	int *p;

	a = p;   // errore: a è un puntaore costante, non lo posso cambiare assegnando un altro indirizzo	
	p = a++; // errore: a è un puntaore costante, non lo posso incrementare con operatore ++ ma (a+1) ok
	p = &a;  // errore: a è un puntaore costante, non posso accedere al suo indirizzo
}

