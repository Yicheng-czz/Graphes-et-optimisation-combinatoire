#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int* FS;
	int* APS;
	int nbSom;
}FdS;

void succSom(FdS fds, int som){
	int indexFs = fds.APS[som-1];

	for(int i = indexFs; i < fds.APS[som]; i++){
		printf("%d\n", fds.FS[i]);
	}
}



