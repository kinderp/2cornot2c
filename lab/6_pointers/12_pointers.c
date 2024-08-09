#include<stdio.h>  // printf()
#include<stdlib.h> // malloc(), free()
#include<string.h> // strcpy()

#define N_ROWS 9
#define N_COLS 8

char **alloc_planets_mat_dyn(int n_rows, int n_cols);
void initialize_planets_mat_dyn(char **matrix);
void print_all_chars(char **array_of_pointers, char static_matrix[][N_COLS], char **dynamic_matrix);
void print_just_strings(char **array_of_pointers, char static_matrix[][N_COLS], char **dynamic_matrix);
void dealloc_planets_mat_dyn(char **matrix, int n_rows);
	
int main(void){
	char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};
	char planets_mat[N_ROWS][N_COLS] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};
	char **planets_mat_dyn = alloc_planets_mat_dyn(N_ROWS, N_COLS);
	initialize_planets_mat_dyn(planets_mat_dyn);

	print_all_chars(planets, planets_mat, planets_mat_dyn);

	printf("\n\n");
	print_just_strings(planets, planets_mat, planets_mat_dyn);

	dealloc_planets_mat_dyn(planets_mat_dyn, N_ROWS);
	return 0;
}

char **alloc_planets_mat_dyn(int n_rows, int n_cols){
	char **matrix = (char **)malloc(n_rows*sizeof(char *)); /* alloco un vettore di puntatori a char (le righe) */
	for(int i=0; i<n_rows; i++)
		matrix[i] = (char *)malloc(n_cols*sizeof(char)); /* alloco un vettore di caratteri (le collonne di una riga) */
	return matrix;
}


void dealloc_planets_mat_dyn(char **matrix, int n_rows){
	/* prima dealloco le righe */
	for(int i=0; i<n_rows; i++)
		free(matrix[i]);
	/* poi il vettore di puntatori a char */
	free(matrix);
}	
void initialize_planets_mat_dyn(char **matrix){
	
	/*
	matrix[0] = "Mercury";
	matrix[1] = "Venus";
	matrix[2] = "Earth";
	matrix[3] = "Mars";
	matrix[4] = "Jupiter";
	matrix[5] = "Saturn";
	matrix[6] = "Uranus";
	matrix[7] = "Neptune";
	matrix[8] = "Pluto";
	*/
	
	strcpy(matrix[0], "Mercury");
	strcpy(matrix[1], "Venus");
	strcpy(matrix[2], "Earth");
	strcpy(matrix[3], "Mars");
	strcpy(matrix[4], "Jupiter");
	strcpy(matrix[5], "Saturn");
	strcpy(matrix[6], "Uranus");
	strcpy(matrix[7], "Neptune");
	strcpy(matrix[8],"Pluto");

}

void print_all_chars(char **array_of_pointers, char static_matrix[][N_COLS], char **dynamic_matrix){
	for(int i=0; i<N_ROWS; i++){
		for(int j=0; j<N_COLS; j++){
			printf("%c ", array_of_pointers[i][j]);
			if(array_of_pointers[i][j] == '\0') break;
		}
		printf("\n");
	}

	printf("\n");


	for(int i=0; i<N_ROWS; i++){
		for(int j=0; j<N_COLS; j++){
			printf("%c ", static_matrix[i][j]);
			if(static_matrix[i][j] == '\0') break;
		}
		printf("\n");
	}

	printf("\n");


	for(int i=0; i<N_ROWS; i++){
		for(int j=0; j<N_COLS; j++){
			printf("%c ", dynamic_matrix[i][j]);
			if(dynamic_matrix[i][j] == '\0') break;
		}
		printf("\n");
	}

	printf("\n");
}


void print_just_strings(char **array_of_pointers, char static_matrix[][N_COLS], char **dynamic_matrix){
	for(int i=0; i<N_ROWS; i++)
		printf("%s\n", array_of_pointers[i]);

	printf("\n");


	for(int i=0; i<N_ROWS; i++)
		printf("%s\n", static_matrix[i]);

	printf("\n");

	for(int i=0; i<N_ROWS; i++)
		printf("%s\n", dynamic_matrix[i]);

	printf("\n");

}
