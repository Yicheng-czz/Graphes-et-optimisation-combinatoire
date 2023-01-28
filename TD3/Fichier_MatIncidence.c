#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int nbSom;
	int nbArc;
	int **mat;
}MatIncid;

MatIncid allocMatIncid(int nbS, int nbA){
	MatIncid mi;
	mi.nbSom = nbS;
	mi.nbArc = nbA;
	mi.mat = (int**)malloc(sizeof(int*) * nbS);
	for(int i = 0; i < nbS; i++){
		mi.mat[i] = (int*)malloc(sizeof(int) * nbA);
	}
	return mi;
}

void initMat(int*** mat,int nbS, int nbA, int initChiffre){
	for(int i = 0; i < nbS; i++){
		for(int j = 0; j < nbA; j++){
			(*mat)[i][j] = initChiffre;
		}
	}
}

MatIncid lectFichier(FILE* f){
	int type,nbSom,nbArc,a,s,t;
	fscanf(f,"#MatriceIncidence\n#1 = Oriente, 2 = nonOriente\n");
	fscanf(f,"typeGraphe = %d\n",&type);
	fscanf(f,"nbSom = %d\n",&nbSom);
	fscanf(f,"nbArc = %d\n",&nbArc);
	MatIncid mi = allocMatIncid(nbSom,nbArc);
	initMat(&(mi.mat),nbSom,nbArc,0);
	for(int i = 0; i < nbArc; i++){
		fscanf(f,"arc=%d s=%d t=%d\n",&a,&s,&t);
		mi.mat[s-1][i] = 1;
		mi.mat[t-1][i] = -1;
	}

	fscanf(f,"#FIN");
	return mi;
}

void afficherMatIncid(MatIncid mi){
	printf("Affichage de la matrice d'incidente : \n");
	for(int i = 0; i < mi.nbSom; i++){
		for(int j = 0; j < mi.nbArc; j++){
			printf("%d\t",mi.mat[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	FILE* f;
	f = fopen("Mat_Incidence.txt","r");
	MatIncid mi = lectFichier(f);
	afficherMatIncid(mi);
	return 0;
}








