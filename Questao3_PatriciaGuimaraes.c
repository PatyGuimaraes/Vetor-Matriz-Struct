//3. Crie uma estrutura para descrever restaurantes. Os membros devem armazenar o 
//nome, o endere�o, o pre�o m�dio e o tipo de comida. Crie uma matriz de estruturas e 
//escreva um programa que utilize uma fun��o para solicitar os dados de um elemento da 
//matriz e outra para listar todos os dados.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

typedef struct endereco{
	char rua[30];
	char bairro[30];
	char cidade[30];
	char estado[2];
}end;

typedef struct comida{
	char nomeRest[30];
	end endereco;
	char tipoComida[20];
	float preco;
}rest;
#define MAX 2

void cadastroRestaurantes(rest *restaurante);
void listarRestaurantes(rest *restaurante);

int main(){
	rest restaurante[MAX];// estou com d�vidas quando matriz, como fica a fun��o. Por isso fiz com vetor.	
	int i=0, opcao, opcao1;
	setlocale (LC_ALL, "Portuguese");
	
	do{
		puts("Escolha uma op��o:");//Estou com dificuldade aqui porque deveria em cada cadastramento pedir a opcao.
		puts("\t1 - Solicitar Dados");
		puts("\t2 - Listar Dados");
		puts("\t3 - Sair");
		scanf("%i", &opcao);
		switch (opcao){
			case 1:
				printf("Deseja cadastrar um novo restaurante  10 - sim, 20 - n�o: ");
				scanf("%i", &opcao1);
				if(opcao1 == 10){
					i++;
				cadastroRestaurantes(restaurante);	
				break;
			case 2:
				listarRestaurantes(restaurante);
				break;
			case 3:
				exit(1);
				break;
			default:
				puts("Op��o inv�lida.");
		}
		
	}while(opcao==1 || i<MAX);
	return 0;
}
void cadastroRestaurantes(rest *restaurante){
	int i;
	puts("----Cadastro dos Restaurantes----");
		printf("Informe o nome do %i� restaurante :", i+1);//Devido o uso do locale n�o h� necessidade de colocar tabela ASC para imprimir �
		fflush(stdin);
		fgets(restaurante[i].nomeRest, 30, stdin);
		puts("--Informe endere�o--");
		puts("Rua: ");
		fflush(stdin);
		fgets(restaurante[i].endereco.rua, 30, stdin);
		puts("Bairro: ");
		fflush(stdin);
		fgets(restaurante[i].endereco.bairro, 30, stdin);
		puts("Cidade: ");
		fflush(stdin);
		fgets(restaurante[i].endereco.cidade, 30, stdin);
		puts("Estado: (Sigla)");
		fflush(stdin);
		fgets(restaurante[i].endereco.estado, 2, stdin);
		puts("Informe a especialidade da comida: ");
		fflush(stdin);
		fgets(restaurante[i].tipoComida, 20, stdin);
		puts("Informe a m�dia de pre�o R$: ");
		fflush(stdin);
		scanf("%f", &restaurante[i].preco);

}
void listarRestaurantes(rest *restaurante){
	int i;
	puts("-----Restaurantes-----");
	for(i=0; i<2; i++){
		printf("\n%i� Restaurante: \n", i+1);
		printf("Restaurante %s\n", restaurante[i].nomeRest);
		printf("Endere�o: %s - Bairro: %s - Cidade: %s - Estado: %s\n", restaurante[i].endereco.rua, restaurante[i].endereco.bairro, restaurante[i].endereco.cidade, restaurante[i].endereco.estado);
		printf("Restaurante especializado em comida %s .\n", restaurante[i].tipoComida);
		printf("Pre�o M�dio R$ %.2f \n", restaurante[i].preco);
	}
}



