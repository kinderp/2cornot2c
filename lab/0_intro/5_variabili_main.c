#include <stdio.h>
#include "5_variabili.h"

int main(void){
        int risultato = 0;
        int primo, secondo;
        char operazione;
        for(int i = 0; i < NUM_ITERATIONS; i++){
                printf("Inserisci il primo operando\n");
                scanf("%d", &primo);
                printf("Inserisci il secondo operando\n");
                scanf("%d", &secondo);
                printf("s)Somma d)Differenza m)Moltiplicazione D)Divisione\n");
                scanf(" %c", &operazione);
                switch(operazione){
                        case 's':
                                risultato = somma(primo, secondo);
                                break;
                        case 'd':
                                risultato = differenza(primo, secondo);
                                break;
                        case 'm':
                                risultato = moltiplicazione(primo, secondo);
                                break;
                        case 'D':
                                risultato = divisione(primo, secondo);
                                break;
                        default:
                                printf("Operazione non riconosciuta\n");

                }
                printf("Il risultato e': %d\n", risultato);
        }
}
