#include<stdio.h>
#include<string.h>

struct studente {
	char *nome;
	char *cognome;
	char *matricola;
	int *voti;
	int eta;
	float media;
};

void calcola_media(struct studente *i);
 
int main(void){
	struct studente ottimo;
	struct studente medio;
	struct studente scarso;

	ottimo.nome = "Mario";
	ottimo.cognome = "Rossi";
	ottimo.matricola ="1234qwert";
	ottimo.eta = 21;
	ottimo.media = 0;
	int tmp1[10] = {28, 30, 30, 30, 29,27,28, 30, 30, 30};
	ottimo.voti = tmp1;

	medio.nome = "Andrea";
	medio.cognome = "Verdi";
	medio.matricola ="9876zxcvb";
	medio.eta = 24;
	medio.media = 0;
	int tmp2[10] = {26, 27, 24, 25, 26, 27, 23, 25, 24, 25};
	medio.voti = tmp2;	

	scarso.nome = "Luigi";
	scarso.cognome = "Bianchi";
	scarso.matricola ="5678lkjhg";
	scarso.eta = 31;
	scarso.media = 0;
	int tmp3[10] = {18, 20, 23, 18, 19, 22, 18, 20, 20, 19};
	scarso.voti = tmp3;	

	calcola_media(&ottimo);
	calcola_media(&medio);
	calcola_media(&scarso);

	printf("%s %s di eta' %d ha una media di %f\n", ottimo.nome, ottimo.cognome, ottimo.eta, ottimo.media);
	printf("%s %s di eta' %d ha una media di %f\n", medio.nome, medio.cognome, medio.eta, medio.media);
	printf("%s %s di eta' %d ha una media di %f\n", scarso.nome, scarso.cognome, scarso.eta, scarso.media);

	return 0;
}

void calcola_media(struct studente *i){
	float media = 0.0;
	for(int j=0; j<10; j++)
		i->media += i->voti[j];
	i->media = i->media / 10;  
}

