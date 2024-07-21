#include<stdio.h>

#define SOMMA(x,y) ((x)+(y))
#define DIFFERENZA(x,y) ((x)-(y))
#define MOLTIPLICAZIONE(x,y) ((x)*(y))
#define DIVISIONE(x,y) ((x)/(y))


int main(void){
        int risultato = 0;
        int primo, secondo;
        char operazione;
        printf("Inserisci il primo operando\n");
        scanf("%d", &primo);
        printf("Inserisci il secondo operando\n");
        scanf("%d", &secondo);
        printf("s)Somma d)Differenza m)Moltiplicazione D)Divisione\n");
        scanf(" %c", &operazione);
        switch(operazione){
                        case 's':
                                risultato = SOMMA(primo, secondo);
                                break;
                        case 'd':
                                risultato = DIFFERENZA(primo, secondo);
                                break;
                        case 'm':
                                risultato = MOLTIPLICAZIONE(primo, secondo);
                                break;
                        case 'D':
                                risultato = DIVISIONE(primo, secondo);
                                break;
                        default:
                                printf("Operazione non riconosciuta\n");

        }
        printf("Il risultato e': %d\n", risultato);
}
