#include<stdio.h>

#define TRACE(var, val) printf("[%s (%d): %s]\t%s=%d\n", \
	__FILE__, __LINE__, __func__, var, val)

int main(void){
	int i;
	#ifdef DEBUG
		TRACE("i", i);
		printf("int i = %d\n", i);
	#else
		printf("int i = %d\n", i);
	#endif /* DEBUG */
	return 0;
}
