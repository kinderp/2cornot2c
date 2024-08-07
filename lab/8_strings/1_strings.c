#include<stdio.h>

int main(void){
        char *ciao = "ciao";
        for(int i=0; i < 5; i++)
                printf("%c \t", ciao[i]);
        printf("\n");

        for(int i=0; i < 5; i++)
                printf("%d \t", ciao[i]);
        printf("\n");
        return 0;
}
