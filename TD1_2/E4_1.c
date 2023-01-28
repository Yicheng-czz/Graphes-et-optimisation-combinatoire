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

liste allocListe(int somAdj){
	liste t = (liste)malloc(sizeof(struct cellule));
	t.sommetAdj = somAdj;
	t.suivant = NULL;
	return t;
}

void InsertV(liste l, int somAdj){
	liste t = allocListe(somAdj);
	l = t;
}

liste suivant(liste l){
	return l->suivant;
}

int estVide(liste l){
	return l==NULL? 1:0;
}

liste queue(liste l){
	liste p = l;
	while(!estVide(suivant(p))){
		p = suivant(p);
	}
	return p;
}

void InsertG(liste l, int somAdj){
	liste p = queue(l);
	liste t = allocListe(somAdj);
	p->suivant = t;
}

void Insert(liste l, int sommetAdj){
	if(estVide(l)){
		InsertV(l,sommetAdj);
	}
	else{
		InsertG(l,sommetAdj);
	}
}

int nbSommet(int** matriceAdj){
	return sizeof(matriceAdj)/sizeof(matriceAdj[0]);
}

liste* allouerTab(int nbSom){
	liste* t = (liste*)malloc(sizeof(liste) * nbSom);
	return t;
}

ListAdj allocListAdj(int** matriceAdj){
	ListAdj la;
	la.nbSom = nbSommet(matriceAdj);
	la.tab = allouerTab(la.nbSom);
}

void initListAdj(int** matriceAdj){
	ListAdj la = allocListAdj(matriceAdj);

	for(int i = 0; i < la.nbSom; i++){
		liste l = la.tab[i];
		for(int j =0; j < la.nbSom; j++){
			if(tab[i][j] != 0){
				Insert(l,j);
			}
		}
	}
}


















