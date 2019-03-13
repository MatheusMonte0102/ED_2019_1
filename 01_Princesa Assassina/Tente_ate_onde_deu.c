#include <stdio.h>
#include <stdbool.h>

void mostrar_vetor(int n_participantes, int vet_participantes[], int escolhido){
	bool eh_primeiro = true;
	int i = 0;
	printf("[");
	for(i = 0; i < n_participantes; i++){
		if(vet_participantes[i] != 0){
			if(eh_primeiro){
				eh_primeiro = false;
			}
			else if(!eh_primeiro){
				printf(" ");
			}
			printf("%d", vet_participantes[i]);
		}
		if(i == escolhido) printf("E");
	}
	printf("]\n");
}
void positivo_negativo(int n_participantes, int vet_participantes[], int primeiro){
	bool eh_positivo = true;
	int i = 0;
	if(primeiro == -1) eh_positivo = false;
	for(i = 0; i< n_participantes; i++)
	{
		if(!eh_positivo){
			vet_participantes[i] = vet_participantes[i] * -1;
			eh_positivo = true;
		}
		else
		{
			eh_positivo = false;
		}
	}
}
int proximo_vivo_negativo(int n_participantes, int escolhido, int vet_participantes[], int primeiro)
{
	int proximo = (escolhido - 1) % n_participantes;
	
		while(vet_participantes[proximo] == 0)
		{
			proximo = (proximo - 1) % n_participantes;
				   
		    if(proximo == 0) proximo = n_participantes - 1;
		}
	return proximo;
}
int proximo_vivo_positivo(int n_participantes, int escolhido, int vet_participantes[], int primeiro)
{
	   int proximo = (escolhido + 1) % n_participantes;
		   while(vet_participantes[proximo] == 0)
		   {
			   proximo = (proximo + 1) % n_participantes;
			   
		   }
		   
	return proximo;   
	   	
}
int main(){
	int n_participantes = 0; // Número de participantes
	int escolhido = 0;
	int primeiro = 0;
	scanf("%d %d %d", &n_participantes, & escolhido, &primeiro);
	escolhido = escolhido -1;	
	int vet_participantes[n_participantes];
	int i = 0;
	for(i = 0; i < n_participantes; i++){
		vet_participantes[i] = i + 1;
	}
	positivo_negativo(n_participantes, vet_participantes, primeiro);
	mostrar_vetor(n_participantes, vet_participantes, escolhido);
	
	int qtd_vivos = n_participantes -1;
	int vai_morrer = 0;
	
	while(qtd_vivos--)
	{
		if(vet_participantes[escolhido] > 0){
			vai_morrer = proximo_vivo_positivo(n_participantes, escolhido, vet_participantes, primeiro);
			vet_participantes[vai_morrer] = 0;
		}
		else if(vet_participantes[escolhido] < 0){
			vai_morrer = proximo_vivo_negativo(n_participantes, escolhido, vet_participantes, primeiro);
			vet_participantes[vai_morrer] = 0;
		}
		if(vai_morrer > 0){
			escolhido = proximo_vivo_positivo(n_participantes, vai_morrer, vet_participantes, primeiro);
		}
		else
		{
			escolhido = proximo_vivo_positivo(n_participantes, vai_morrer, vet_participantes, primeiro);
		}
		mostrar_vetor(n_participantes, vet_participantes, escolhido);
		
	}
	
	
	
	
	
	return 0;
}