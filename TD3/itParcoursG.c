#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int nbSom;
	int **mat;
}MatAdj;

MatAdj allocSMA(int nb){
	MatAdj ma;
	ma.nbSom = nb;
	ma.mat = (int**)malloc(sizeof(int*) * nb);
	for(int i = 0; i < nb; i++){
		ma.mat[i] = (int*)malloc(sizeof(int) * nb);
	}
	return ma;
}

void initMat(int*** mat, int p, int nbSom){
	for(int i = 0; i < nbSom; i++){
		for(int j = 0; j < nbSom; j++){
			(*mat)[i][j] = p;
		}
	}
}

MatAdj lectFicher(FILE* f){
	MatAdj ma;
	int n,p;
	fscanf(f,"#Mat d'adj et leurs degrees");
	fscanf(f,"\nnbSom = %d",&n);
	printf("%d\n", n);
	fscanf(f,"\nnbArc = %d",&p);
	printf("%d\n", p);
	ma = allocSMA(n);
	initMat(&(ma.mat),0,n);
	int som,nbSucc,t;
	// sommet
	for(int i = 0; i < n; i++){
		fscanf(f,"\nsom=%d nbSucc=%d succ=",&som,&nbSucc);
		printf("som=%d, nbSucc=%d, ",som,nbSucc);
		// combien de succ;
		for(int j = 0; j < nbSucc; j++){
			fscanf(f," %d",&t);
			printf("%d ",t);
			ma.mat[i][t-1] = 1;
		}
		printf("\n");
		
	}
	fscanf(f,"\n#FIN");
	return ma;
}

int nbSom(MatAdj ma){
	return ma.nbSom;
}

void afficherMat(MatAdj ma){
	int nb = nbSom(ma);
	for(int i = 0; i < nb; i++){
		for(int j = 0; j < nb; j++){
			printf("%d ",ma.mat[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	FILE* f;
	f = fopen("graphe.txt","r");
	if(f == NULL){
		exit(1);
	}
	MatAdj ma = lectFicher(f);
	afficherMat(ma);
	return 0;
}




















