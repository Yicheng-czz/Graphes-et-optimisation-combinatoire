#include<stdio.h>
#include<stdlib.h>

typedef struct cellule{
	int sommetAdj;		// le nom du sommet
	// TCout cout;
	struct cellule* suivant; 
}*liste;

typedef struct{
	int nbSom;
	liste* tab;
}ListAdj;

int estVide(liste l){
	return l == NULL? 1 : 0;
}

int countListe(liste l){
	int i = 0;
	while(!estVide(l)){
		++i;
	}
	return i;
}

int plusSucc(ListAdj la){
	liste* t = la.tab;
	int max = 0;
	int tmp = 0;
	int indexMax = 0;
	for(int i = 0; i < la.nbSom; i++){
		tmp = countListe(t[i]);
		if(tmp > max){
			max = tmp;
			indexMax = i;
		}
	}
	return indexMax;
}

















