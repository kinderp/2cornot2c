#include<stdio.h>  // printf()

int accumulate(int);

int count;

int main(void){
	int number;
	int total = 0;
	while(1){
		printf("Get me an integer > 0 (0 to quit)\n");
		scanf("%d", &number);
		++count;
		if(number == 0)
			break;
		total = accumulate(number);
	}
	printf("total=%d\n", total);
	return 0;
}
