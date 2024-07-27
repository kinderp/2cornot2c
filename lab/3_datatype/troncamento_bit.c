#include<stdio.h>

int main(void){
	int x = 53191;
	/* castando int x a short avremo il trocamento dei 16 bit (MSB) */
	short sx = (short) x; /* -12345 */
	int y = sx;	      /* -12345 signed short 2 signed con sign extension */
	printf("x  = %d \t %x\n", x, x);
	printf("sx = %hd \t %hx\n", sx, sx);  
	printf("y  = %d \t %x\n", y, y);
	return 0;
}
