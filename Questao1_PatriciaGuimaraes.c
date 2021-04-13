//1. Considerando o conjunto de dados abaixo para cria��o da estrutura, crie um programa 
//em C que leia o pre�o, o nome e as baixas de todos os dias de todos os produtos, ap�s 
//percorra a estrutura de dados e verifique qual foi o produto que teve mais baixa, ou seja, 
//que foi mais vendido. Ao final, mostre o nome e quantas unidades deste produto foram 
//vendidas. A estrutura deve conter: c�digo, nome, pre�o, baixa como uma matriz 4X6, 
//onde o 4 representa as semanas e o 6 cada dia da semana (segunda a s�bado)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

typedef struct dados{
	char nomeProd[30];
	double precoProduto;
	int cod, baixaEstoque;

}prod;

int main (){
	setlocale(LC_ALL, "Portuguese");
	prod vendaMensal[4][6], prodMaiorBaixa;//prodMaiorBaixa - vari�vel para fazer a compara��o dentro da matriz e apresentar o que se pede.
	int i, j;


	for(i=0; i<4; i++){
		for(j=0; j<6; j++){
			printf("Informe o c�digo XXX do produto: \n");
			fflush(stdin);
			scanf("%d", &vendaMensal[i][j].cod);
			printf("Informe o nome do produto: \n");
			fflush(stdin);
			fgets(vendaMensal[i][j].nomeProd, 30, stdin);
			printf("Valor do produto: R$ \n");
			fflush(stdin);
			scanf("%d", &vendaMensal[i][j].precoProduto);
			printf("Informe a quantidade vendida: \n");
			fflush(stdin);
			scanf("%d", &vendaMensal[i][j].baixaEstoque);
		}
	}
	prodMaiorBaixa = vendaMensal[0][0];//usei s� a matriz que assim pega todos os atributos da struct.
	
	for(i=0; i<4; i++){
		for(j=0; j<6; j++){
			if (vendaMensal[i][j].baixaEstoque > prodMaiorBaixa.baixaEstoque){//aqui comparei somente com baixaEstoque
				prodMaiorBaixa = vendaMensal[i][j];//J� pecorreu toda a matriz e atribuiu a vari�vel prodMaiorBaixa
				
			}	
		}
	}
	system("cls");
	printf("----Apresenta��o das Vendas----\n");
	printf("Nome do produto mais vendido: %s ", prodMaiorBaixa.nomeProd);//apresenta o nome do produto que foi o mais vendido.
	printf("Quantidade vendida: %i unidades.\n", prodMaiorBaixa.baixaEstoque);//apresenta a maior baixa em estoque, ou seja o prod mais vendido.

	
}
