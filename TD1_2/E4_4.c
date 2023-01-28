#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int nbSom;
	int nbArc;
	int *FS;
	int *APS;
}FileSucc;

typedef struct cellule{
	int somAdj;
	// TCout tcout;
	struct cellule* suivant;
}*List;

typedef struct{
	int nbSom;
	List* tab;
}ListAdj;

List suivant(List l){
	return l->suivant;
}

List* allocList(int nb){
	List* l = (List*)malloc(sizeof(List) * nb);
	return l;
}

ListAdj allocListAdj(int nb){
	ListAdj la;
	la.nbSom = nb;
	la.tab = allocList(nb);
	return la;
}

List allocCellule(int somAdj){
	List l = (List)malloc(sizeof(struct cellule));
	l->somAdj = somAdj;
	l->suivant = NULL;
	return l;
}

List insertTete(List l,int somAdj){
	List ln = allocCellule(somAdj);
	ln->suivant = l;
	l = ln;
	return l;
}

void initListAdj(ListAdj la, FileSucc fs){
	int j=0;
	for(int i = 0; i < fs.nbSom; i++){
		for(int j = fs.APS[i]; j < fs.APS[i+1]; j++){
			la.tab[i] = insertTete(la.tab[i],fs.FS[j]);
		}
	}
}

void parcoursList(List l){
	List tmp = l;
	while(tmp != NULL){
		printf("%d -> ", tmp->somAdj);
		tmp = suivant(tmp);
	}
}

void afficher(ListAdj la){
	for(int i = 0; i < la.nbSom; i++){
		printf("[%d] : ",i+1);
		parcoursList(la.tab[i]);
		printf("\n");
	}
}

int main(){

	int fs_fs[5] = {5,5,1,7,4};
	int fs_aps[8] = {0,0,1,2,3,4,5,5};
	FileSucc fs = {7, 5, fs_fs,fs_aps};

	ListAdj la = allocListAdj(7);
	initListAdj(la,fs);
	afficher(la);

	return 0;
}