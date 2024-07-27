#include<stdio.h>

int main(void){
	int tx, ty;
	unsigned ux, uy;
	ux = 4294967295; /* il cast cambia il valore */
	ty = 2147483647; /* il cast non cambia il valore */
	int tx_, ty_;
	unsigned ux_, uy_;

	ux_ = ux;
	ty_ = ty;
	/* cast esplicito */
	tx = (int) ux;
	uy = (unsigned) ty;

	/* cast implicito */
	tx_ = ux_;
	uy_ = ty_;

	printf("unsigned = %ld byte\n", sizeof(unsigned int));
	printf("     int = %ld byte\n", sizeof(int));
	printf("\n");

	printf("ux = %u, tx = %d\n", ux, tx);
	printf("ux_ = %u, tx_ = %d\n", ux_, tx_);
	printf("\n");

	printf("uy = %u, ty = %d\n", uy, ty);
	printf("uy_ = %u, ty_ = %d\n", uy_, ty_);
	printf("\n");

	/* se prendo un valore intero negativo allora cambia il valore castando verso unsigned */
	int cast_me = -2147483648; /* TMin */
	int u_cast_me = (unsigned) cast_me; /* Tmax+1 = (unsigned) TMin */
	printf("cast_me = %d, u_cast_me = %u\n", cast_me, u_cast_me);

}
