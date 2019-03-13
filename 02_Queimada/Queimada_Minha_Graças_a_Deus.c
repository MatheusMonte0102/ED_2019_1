#include <Stdio.h>
#include <stdlib.h> // srand, rand
#include <time.h> // time()



int deslocamento_L[] = {0, -1, 0, 1}; // Vetor que diz em quais posições da matris eu vou andar num laço
int deslocamento_C[] = {-1, 0, 1, 0}; // Vetor que diz em quais posicoes da matriz eu vou andar num laço
int qtd_lados = sizeof(deslocamento_L) / sizeof(int); /*Fazendo isso facilita quando eu quiser andar pelas diagonais
e tambem eu ei quatas posicoes eu tenho no meu vetor*/

void embaralhar(int vet[], int size){
	int i = 0;
	for(i = 0; i < size; i++){
		int esc = rand() % size;
		int temp = vet[i];
		vet[i] = vet[esc];
		vet[esc] = temp; 
	}
}
void mostrar_arvore(int num_lin, int num_col, char mat[num_lin][num_col]){
	int l = 0;
	for(l = 0; l < num_lin; l++){
		int c = 0;
		for(c = 0; c < num_col; c++){
			printf("%c", mat[l][c]);
		}
		puts("");
	}
	//getchar();
}

int incendiar_arvore(int num_lin, int num_col, char mat[num_lin][num_col], int linha, int coluna){
	int cont = 0; //Contador de arvores queimadas.
	if((num_lin <= linha) || (linha < 0) || (num_col <= coluna) || (coluna < 0)){
		return 0;
	}
	if(mat[linha][coluna] != '#'){
		return 0;
	}
	mat[linha][coluna] = 'o';
	mostrar_arvore(num_lin, num_col, mat);
	getchar();
	// Left, up, right, Donw
	cont = 1;
	int v = 0;
	int vizinho[] = {0, 1, 2, 3};
	embaralhar(vizinho, qtd_lados);
	for(v = 0; v < qtd_lados; v++){ //Graças a Deus deu certo
		int i = vizinho[v];
		cont += incendiar_arvore(num_lin, num_col, mat, linha +deslocamento_L[i], coluna +deslocamento_C[i]);
	}
	mat[linha][coluna] = 'x';
	mostrar_arvore(num_lin, num_col, mat);
	getchar();
	return cont;
}

int main(){
	srand(time(NULL));
	int num_lin = 0;
	int num_col = 0;
	puts("Digite as dimensoes da matriz");
	scanf("%d %d", &num_lin, &num_col);
	char mat[num_lin][num_col];
	puts("Digite a porcentagem de espacos vazios 0-100");
	int VOID = 0;
	scanf("%d", &VOID);
	int i = 0;
	for(i = 0; i < num_lin; i++){
		int j = 0;
		for(j = 0; j < num_col; j++){
			if(rand() % 101 <= VOID) // Muita duvida aqui
				mat[i][j] = '.';
			else
			   mat[i][j] = '#';	
		}
	}
	mostrar_arvore(num_lin, num_col, mat);
	int linha = 0;
	int coluna = 0;
	printf("Onde o fogo vai iniciar\n");
	scanf("%d %d", &linha, &coluna);
	
	int cont = incendiar_arvore(num_lin, num_col, mat, linha, coluna);
	printf("Total do estrago: %d", cont);
	
	return 0;
}