#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int nbSom;
	int nbArc;
	int *FS;
	int *APS;
}FileSucc;


typedef struct{
	int nbSom;
	int **mat;
	// TCout** tcout;
}MatAdj;


int* allouerTab(int nb){
	int* tab = (int*)malloc(sizeof(int) * nb);
	return tab;
}


FileSucc allocMemSFS(int n, int p){
	FileSucc fs;
	fs.nbSom = n;
	fs.nbArc = p;
	fs.FS = allouerTab(p);
	fs.APS = allouerTab(n+1);
	return fs;
}


int nbSomMA(MatAdj ma){
	return ma.nbSom;
}


int nbArcsMA(MatAdj ma){
	int somme = 0;
	for(int i = 0; i < nbSomMA(ma); i++){
		for(int j = 0; j < nbSomMA(ma); j++){
			if(ma.mat[i][j] == 1){
				somme++;
			}
		}
	}
	return somme;
}


FileSucc conv(MatAdj ma){
	int n = nbSomMA(ma);
	int p = nbArcsMA(ma);
	FileSucc fs = allocMemSFS(n,p);
	int iaps = 0,i,j;

	for(i = 0; i < n; i++){
		fs.APS[i] = iaps;
		for(j = 0; j < n; j++){
			if(ma.mat[i][j] == 1){
				fs.FS[iaps] = j;
				++iaps;
			}
		}
	}
	fs.APS[i] = iaps;
	return fs;
}


int main(){

	MatAdj ma;
	ma.nbSom = 6;
	
	int** mat = (int**)malloc(sizeof(int*) * (ma.nbSom));
	for(int i = 0; i < ma.nbSom; i++){
		mat[i] = (int*)malloc(sizeof(int) * (ma.nbSom));
		for(int j = 0; j < ma.nbSom; j++){
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

	ma.mat = mat;

	FileSucc fs = conv(ma);

	for(int i = 0; i < 7; i++){
		printf("%d ->",fs.APS[i]);
	}

	return 0;
}











