#include<stdio.h>

void one(void);
void two(void);

static int global_internal;

int main(void){
	printf("global_internal=%d\n", global_internal);
	one();
	two();
}

void one(void){
	global_internal++;
	printf("global_internal=%d\n", global_internal);
}

void two(void){
	global_internal++;
	printf("global_internal=%d\n", global_internal);
}
