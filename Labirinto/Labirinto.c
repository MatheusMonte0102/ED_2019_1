#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//const char Inquebravel = 'H';
const char Parede = '#';
const char espaco = '.';
int deslo_L[] = {0, -1, 0, 1};
int deslo_C[] = {-1, 0, 1, 0};

/*int eh_furavel(int num_linhas, int num_colunas, int linhas, int colunas, char matriz[num_linhas][num_colunas]){
	//left, up, right, donw
	if(matriz[linhas][colunas - 1] == Parede) return 1; //left
	else if(matriz[linhas - 1][colunas] == Parede) return 1; //up
	else if(matriz[linhas][colunas +1] == Parede) return 1; //right
	else if(matriz[linhas + 1][colunas] == Parede) return 1; // donw
		else return 0;
}*/

void embaralha(vet[]){
	int i = 0;
	for(i = 0; i < 4; i++){
		
	}
}
	

void mostra_labirinto(int num_linhas, int num_colunas, char mat[num_linhas][num_colunas]){
	int l = 0;
	int c = 0;
	for(l = 0; l < num_linhas; l++){
		for(c = 0; c < num_colunas; c++){
			printf("%c", mat[l][c]);
		}
		puts("");
	}
	getchar();
}
void proximo_furavel(int num_linhas, int num_colunas, int linhas, int colunas, char matriz[num_linhas][num_colunas]){
	if((linhas >= num_linhas - 1) || (linhas < 1) || (colunas >= num_colunas - 1) || (colunas < 1))
		return;
	if(matriz[linhas][colunas] != Parede)
		return;
	if((matriz[linhas][colunas - 1] == espaco) || (matriz[linhas - 1][colunas] == espaco) || (matriz[linhas][colunas +1] == espaco) || (matriz[linhas + 1][colunas] == espaco))
		return;
	matriz[linhas][colunas] = espaco;
	mostra_labirinto(num_linhas, num_colunas, matriz);
	int i = 0;
	
	for(i = 0; i < 4; i++){
		proximo_furavel(num_linhas, num_colunas, linhas + deslo_L[i], colunas + deslo_C[i], matriz);
	}
	
	
}
int main(){
	srand(time(NULL));
	int num_linhas = 0;
	int num_colunas = 0;
	 printf("Digite o tamanho do labirinto\n");
	scanf("%d %d", &num_linhas, &num_colunas);
	
	char mat[num_linhas][num_colunas];
	int l = 0;
	int c = 0;
	for(l = 0; l < num_linhas; l++){
		for(c = 0; c < num_colunas; c++){ 
			mat[l][c] = Parede;
		}
	}
	
	puts("Digite onde quer comecar");
	int linha = 0;
	int coluna = 0;
	scanf("%d %d", &linha, &coluna);
	
	mostra_labirinto(num_linhas, num_colunas, mat);
	proximo_furavel(num_linhas, num_colunas, linha, coluna, mat);
	
	return 0;
}