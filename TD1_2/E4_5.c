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




int main(){



}