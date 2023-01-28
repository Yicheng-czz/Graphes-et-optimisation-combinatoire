#include<stdio.h>
#include<stdlib.h>

typedef struct celluleS{
	int somAdj;		// le nom du sommet
	// TCout tcout;
	struct celluleS* suivant;
}*LS;

typedef struct celluleP{
	int somAdj;		// le nom du sommet
	// TCout tcout
	struct celluleP* pred;
}*LP;

typedef struct cellule{
	LS ls;
	LP lp;
}List;

typedef struct{
	int nbSom;
	List* tab;
}SomTab;

LS suivant(LS ls){
	return ls->suivant;
}

LP pred(LP lp){
	return lp->pred;
}

List* allocTab(int nb){
	List* list_tab = (List*)malloc(sizeof(List) * nb);
	return list_tab;
}

SomTab allocSomTab(int nb){
	SomTab st;
	st.nbSom = nb;
	st.tab = allocTab(nb);
	return st;
}

LP allocMemRem_Pred(int sommet){
	LP lp = (LP)malloc(sizeof(struct celluleP));
	lp->somAdj = sommet;
	lp->pred = NULL;
	return lp;
}

LS allocMemRem_Suiv(int sommet){
	LS ls = (LS)malloc(sizeof(struct celluleS));
	ls->somAdj = sommet;
	ls->suivant = NULL;
	return ls;
}

LP insertTete_Pred(LP lp, int sommet){
	LP lp_n = allocMemRem_Pred(sommet);
	lp_n->pred = lp;
	lp = lp_n;
	return lp;
}

LS insertTete_Suiv(LS ls, int sommet){
	LS ls_n = allocMemRem_Suiv(sommet);
	ls_n->suivant = ls;
	ls = ls_n;
	return ls;
}

void initSomTab(SomTab st, int** mat){
	int i,j;
	List l;
	for(i = 0; i < st.nbSom; i++){
		l = st.tab[i];
		for(j = 0; j < st.nbSom; j++){
			if(mat[i][j] == 1){
				l.ls = insertTete_Suiv(l.ls,i);
			}
		}
	}

	for(i = 0; i < st.nbSom; i++){
		l = st.tab[i];
		for(j = 0; j < st.nbSom; j++){
			if(mat[j][i] == 1){
				l.ls = insertTete_Suiv(l.ls,j);
			}
		}
	}
}

void parcoursPred(LP lp){
	LP tmp = lp;
	while(tmp != NULL){
		printf("%d <- ",lp->somAdj);
		tmp = pred(tmp);
	}
}

void parcoursSuiv(LS ls){
	LS tmp = ls;
	while(tmp != NULL){
		printf("%d -> ",ls->somAdj);
		tmp = suivant(tmp);
	}
}


int main(){

	int nbSommet = 6;
	int** mat = (int**)malloc(sizeof(int*) * (nbSommet));
	for(int i = 0; i < nbSommet; i++){
		mat[i] = (int*)malloc(sizeof(int) * (nbSommet));
		for(int j = 0; j < nbSommet; j++){
			mat[i][j] = 0;
		}
	}
	mat[0][2] = 1;
	mat[1][0] = 1;
	mat[1][2] = 1;
	mat[2][3] = 1;
	mat[2][5] = 1;
	mat[4][3] = 1;
	mat[4][5] = 1;
	mat[5][3] = 1;

	// afficher matrice d'adjcence
	for(int i = 0; i < nbSommet; i++){
		for(int j = 0; j < nbSommet; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

	SomTab st = allocSomTab(nbSommet);
	initSomTab(st,mat);

	List l;
	for(int i = 0; i < nbSommet; i++){
		l = st.tab[i];
		parcoursPred(l.lp);
		printf("[%d] ",i);
		parcoursSuiv(l.ls);
		printf("\n");
	}

	return 0;
}














































