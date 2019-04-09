//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
#include"xvet.h"
#include"xpaint.h"


void show(int vet[], int size){
    int i = 0;
    printf("[");
    for(; i < size; i++)
        printf("%d ", vet[i]);
    printf("]\n");
}
void insertion(int vet[], int size){
    int i = 0;
    int temp = 0;
    int j = 0;
    for(i = 1; i < size; i++){
        temp = vet[i];
        j = i - 1;

        while((j >= 0) && (vet[j] > temp)){
            vet[j + 1] = vet[j];
            j = j - 1;
            }
        vet[j + 1] = temp;
        xd_vet(vet, size, "rg", temp, j);//show(vet, size);
    }
}
int main(){
    x_open(600, 300);
    srand(time(NULL));
    int size = 0;
    int vet[10];
    size = sizeof(vet) / sizeof(int);
    int i = 0;
    for(; i < size; i++){
        vet[i] = rand() % 191 + 10;
    }
    xd_vet(vet, size, "");
    insertion(vet, size);
    xd_vet(vet, size, "");

    return 0;
}