#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

const char Parede = '|';
const char espaco = ' ';
int deslo_L[] = {0, -1, 0, 1};
int deslo_C[] = {-1, 0, 1, 0};

bool eh_furavel(int num_linhas, int num_colunas, int linhas, int colunas, char matriz[num_linhas][num_colunas]){
	int cont = 0;
	if(matriz[linhas][colunas - 1] == espaco)
		cont ++;
	if(matriz[linhas - 1][colunas] == espaco)
		cont ++;
	if(matriz[linhas][colunas + 1] == espaco)
		cont ++;
	if(matriz[linhas + 1][colunas] == espaco)
		cont ++;
	if(cont >= 2)
		return false;
	else
		return true;
	
}

void embaralha(int vizinhos[]){
	int i = 0;
	for(i = 0; i < 4; i++){
		int auxiliar = rand() % 4;
		int aux = vizinhos[i];
		vizinhos[i] = vizinhos[auxiliar];
		vizinhos[auxiliar] = aux;
	}
}
	

void mostra_labirinto(int num_linhas, int num_colunas, char mat[num_linhas][num_colunas] ){
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
	if(matriz[linhas][colunas] == espaco)
		return;
	if(!eh_furavel(num_linhas, num_colunas, linhas, colunas, matriz))
		return;
	matriz[linhas][colunas] = espaco;
	getchar();
	mostra_labirinto(num_linhas, num_colunas, matriz);
	int vizinhos[4] = {0, 1, 2, 3};
	embaralha(vizinhos);
	int i = 0;
	for(i = 0; i < 4; i++){
		int auxiliar = vizinhos[i];
		proximo_furavel(num_linhas, num_colunas, linhas + deslo_L[auxiliar], colunas + deslo_C[auxiliar], matriz);
	}
	
	
}
bool acha_caminho(int num_linhas, int num_colunas, int linhas, int colunas, int l_saida, int c_saida, char mat[num_linhas][num_colunas]){
	mat[l_saida][c_saida] = 'x';
	bool p_desgracado = false;
	//mostra_labirinto(num_linhas, num_colunas, mat);
    if ((mat[linhas][colunas] != espaco) && (mat[linhas][colunas] != 'x') && (mat[linhas][colunas] == Parede))//se nao for ' '
        return false;
    if(mat[linhas][colunas] == '.') //se ja foi visitado
        return false;
    if(mat[linhas][colunas] == 'x'){//se sou saida
		mat[linhas][colunas] = '0';
		return true;
		
	}
    mat[linhas][colunas] = '.'; //marco como visitado
		mostra_labirinto(num_linhas, num_colunas, mat);
	
	int i = 0;
	for(i = 0; i < 4; i++)
		p_desgracado = acha_caminho(num_linhas, num_colunas, linhas + deslo_L[i], colunas + deslo_C[i], l_saida, c_saida, mat);//para cada vizinho
    
	if(p_desgracado){//se alguem retornar verdadeiro
		return true;
	}
	//(mat[linhas][colunas + 1] == 'x') || (mat[linhas + 1][colunas] == 'x') || (mat[linhas - 1][colunas] == 'x') || mat[linhas][colunas - 1])
	else if(!p_desgracado){
		mat[linhas][colunas] = espaco;
	}
		
	else 
		
		return false;
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
	for(; l < num_linhas; l++){
		for(c = 0; c < num_colunas; c++){ 
			mat[l][c] = Parede;
		}
	}
	
	/*puts("Digite onde quer comecar");
	int linha = 0;
	int coluna = 0;
	scanf("%d %d", &linha, &coluna);*/
	proximo_furavel(num_linhas, num_colunas, 1, 1, mat);

	printf("Digite a saída");
	int l_saida = 0;
	int c_saida = 0;
	scanf("%d %d", &l_saida, &c_saida);
	
	acha_caminho(num_linhas, num_colunas, 1, 1, l_saida, c_saida, mat);
	mostra_labirinto(num_linhas, num_colunas, mat);
	
	return 0;
}