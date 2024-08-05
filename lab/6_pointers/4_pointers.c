#include<stdio.h>

int main(void){
	int magic = 16909060;
	int after_magic = 123456789;
	printf("magic        = %#x\n", magic);
	printf("after_magic  = %#x\n", after_magic);

	int *ptr_magic = &magic;
	printf("&magic       = %p\n", ptr_magic);
	printf("&after_magic = %p\n", &after_magic);
	
	char *ptr_byte1 = (char *)ptr_magic;
	char *ptr_byte2 = ptr_byte1 + 1;
	char *ptr_byte3 = ptr_byte1 + 2;
	char *ptr_byte4 = ptr_byte1 + 3;

	printf("ptr_byte1    = %d\n", *ptr_byte1);
	printf("ptr_byte2    = %d\n", *ptr_byte2);
	printf("ptr_byte3    = %d\n", *ptr_byte3);
	printf("ptr_byte4    = %d\n", *ptr_byte4);
	return 0;
}
