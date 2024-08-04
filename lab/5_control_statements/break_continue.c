
#include<stdio.h>

int main(void){
	int i = 0;
	while(1){
		if(i == 10){
			printf("\n");
			break;
		}
		if(i % 2 == 0){
			++i;
			continue;
		}
		printf("%d ", i);
		i++;
	}


	for(int j=0; ; j++){
		if(j == 10){
			printf("\n");
			break;
		}
		if(j % 2 == 0)
			continue;
		printf("%d ", j);
	}
	return 0;
}
