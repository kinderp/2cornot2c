#include<stdio.h>

int main(void){
	short sx = -12345;
	unsigned uy = sx;

	printf("sx = %hd \t\t %hx\n", sx, sx);
	printf("uy = %u  \t %x\n", uy, uy);
}
