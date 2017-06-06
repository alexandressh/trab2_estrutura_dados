/*
 * Programa para testar as operações de arvore binaria de busca
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include "abb.h"

int main(){
	// Variáveis para controle da duracao da ordenação
	int quantidade_entradas=0, casos_de_busca=0, valor=0, cont=0, valorNegativo=0;
	char ch;
	Arvore abb;
	FILE *arq;

	/*INICIALIZACAO*/
	char fileName[99];
	//scanf("%s", fileName);
	//arq = fopen(fileName, "r");
	arq = fopen ("teste.in", "r");

	//printf("Teste abb\n");
	cria_arvore(&abb);
	//printf("arvore iniciada\n");
	/*TIMER*/
	struct timeval start, end;
	long long mtimeDim, mtimeEst, seconds, useconds;
	
	if (arq == NULL) {
	   printf ("Houve um erro ao abrir o arquivo.\n");
	   return 1;
	}
	//printf("Arquivo encontrado\n");
	while((ch=fgetc(arq))!= EOF) {
		cria_arvore(&abb);
		quantidade_entradas=0; casos_de_busca=0; valor=0; cont=0;valorNegativo=0;
		while(ch != ' ') { //QUANTIDADE DE ENTRADAS / NOHS
			quantidade_entradas = (quantidade_entradas * 10) + (ch - '0');
			ch=fgetc(arq);
		}
		printf("Quantidade de entradas: %d\n", quantidade_entradas);
		while(ch != '\n') { //QUANTIDADE DE CASOS DE TESTE
			if(ch != ' ')
				casos_de_busca = (casos_de_busca * 10) + (ch - '0');
			ch=fgetc(arq);
		} 		
		printf("Casos de busca: %d\n", casos_de_busca);
		//printf("Iniciando insercao...\n");
		if(quantidade_entradas != 0) {
			cont = quantidade_entradas-1;
			ch=fgetc(arq);
			while(ch != '\n') {
				if(ch == '-') {
					valorNegativo = 1;
				} else if(ch != ' ') {
					valor = (valor * 10) + (ch - '0');
				} else {
					//printf("inserindo valor: %d\n", valor);
					insere(&abb, valorNegativo==1 ? valor*(-1) : valor);
					cont--; valor = 0; valorNegativo = 0;
				}
				ch=fgetc(arq);
				if(ch == '\n' && cont != 0) {
					//printf("inserindo valor: %d\n", valor);
					insere(&abb, valorNegativo==1 ? valor*(-1) : valor);
					cont--; valor = 0; valorNegativo = 0;
					ch=fgetc(arq); 
				}
			}
			//printf("inserindo valor: %d\n", valor);
			insere(&abb, valorNegativo==1 ? valor*(-1) : valor); //INSERINDO ULTIMO VALOR
			valor = 0; valorNegativo = 0;
			
			//printf("no raiz = %d", abb->info);
			printf("\n"); inorder(abb); printf("\n");
			if(verifica(abb)) { 
				printf("eh uma arvore de busca\n");
			} else {
				printf("Oops...nao eh uma arvore de busca!!!\n");
			}
			
			
			/*INICIANDO BUSCAS*/
			//printf("insercao terminada, iniciando casos de busca\n");
			for(int i=0; i < casos_de_busca; i++) {
				ch=fgetc(arq);
				int menor=0, maior=0;
				while(ch != ' ') {
					if(ch == '-') {
						valorNegativo = 1;
					} else if(ch != ' ') {
						menor = (menor * 10) + (ch - '0');
					}
					ch=fgetc(arq);
				}
				while(ch != '\n') {
					if(ch == '-') {
						valorNegativo = 1;
					} else if(ch != ' ') {
						maior = (maior * 10) + (ch - '0');
					}
					ch=fgetc(arq);
				}
				printf("\nCaso de busca %d: buscando valores entre %d e %d\n", i+1, menor, maior);
				busca_por_intervalo(abb, menor, maior); //decidir retorno da funcao e exibir antes da proxima iteração do for
			}
			
			printf("\n");				
		} else {
			//printf("\n FIM DO ARQUIVO");
			break;
		}
	} 
	fclose (arq);
	return 0;
}
