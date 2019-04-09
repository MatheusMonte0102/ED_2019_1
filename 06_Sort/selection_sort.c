//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
#include "xvet.h"
#include "xpaint.h"

#define SUAPI(a, b, type) do{type aux = a; a = b; b = aux;}while(0)

void show(int vet[], int size){
	int i = 0;
	printf("[ ");
	for(; i < size; i++){
		printf("%d ", vet[i]);
	}
	printf("]\n");
}
int acha_ind_menor(int vet[], int size, int inicio, int fim){
	int i_menor = inicio;
	int i = inicio + 1;
	for(; i < size; i++){
		if(vet[i] < vet[i_menor])
			i_menor = i;
	}
	return i_menor;
}
void selection(int vet[], int size){
	int i = 0;
	for(; i < size; i++){
		int i_menor = acha_ind_menor(vet, size, i, size);
		xd_vet(vet, size, "rb", i_menor, i);
		SUAPI(vet[i], vet[i_menor], int);
		show(vet, size);
		xd_vet(vet, size, "rb", i_menor, i);
	}
}
int main(){
	x_open(600, 300);
	srand(time(NULL));
	int vet[10];
	int size = sizeof(vet) / sizeof(int);
	int i = 0;
	for(; i < 10; i++){
		vet[i] = rand() % 191 + 10;
	}
	selection(vet, size);
	xd_vet(vet, size, "");
	x_close();
	
	
	return 0;
}