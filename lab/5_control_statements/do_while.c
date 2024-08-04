#include<stdio.h>

int main(void){
        int i = 0;
	/* i++ prima viene valutato il  valore di i  (si stampa il suo valore)
	 * dopo i viene incrementata  di 1 ,  poi  si controlla  che  sia < 10 
         * cosa accade se uso ++i?Invece di stampare da 0 a 9 stampo da 1 a 10
	 */
        do {
                printf("%d ", i++);
        } while(i < 10);
        printf("\n");
        return 0;
}

