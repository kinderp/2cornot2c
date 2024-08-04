#include<stdio.h>

int main(void){
        int n;
        printf("Inserisci un numero tra 1 e 10\n");
        scanf("%d", &n);
        int pari_o_dispari = n % 2;
        if(pari_o_dispari == 0){  /* Se la condizione  e' vera (diversa da zero)
				   * il  flusso   entra in questo blocco, stampa
				   * "n e' pari" ed il blocco else viene saltato
				   */
                printf("%d e' pari\n", n);
        } else{			  /* Se la condizione e' falsa ( uguale a zero )
				   * il blocco if viene saltato e si  entra  nel
				   * blocco else e  viene  stampata  la  stringa
				   * "n è dispari" 
				   */
                printf("%d e' dispari\n", n);
        }
        return 0;
}

