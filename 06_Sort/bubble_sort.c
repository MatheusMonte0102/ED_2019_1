#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"xvet.h"
#include"xpaint.h"


#define SUAPI(a, b, type) do{type aux = a; a = b; b = aux;}while(0)
/*void show(int vet[], int size){
    int i = 0;
    printf("[ ");
    for(i; i < size; i++)
        printf("%d ", vet[i]);
    printf("]\n");
}*/
void bubble(int vet[], int size){
    printf("Existyo");
    int i = 0;
    int j = 0;
    for(i; i < size - 1; i++){
        for(j = 0; j < size - 1 - i; j++){
            if(vet[j] > vet[j + 1]){
                SUAPI(vet[j], vet[j + 1], int);
                xd_vet(vet, size, "rb", j, j + 1); // show(vet, size);
            }
        }
    }
}

int main(){
    x_open(800, 500);
    int vet[10];
    int size = sizeof(vet) / sizeof(int);
    srand(time(NULL));
    int i = 0;
    for(; i < size; i++){
        vet[i] = rand() % 161 + 50;
    }
    xd_vet(vet, size, "");
    bubble(vet, size);
    xd_vet(vet, size, "");
    x_close();
    return 0;
}