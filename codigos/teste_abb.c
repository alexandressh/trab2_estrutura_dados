/*
 * Programa para testar as opera��es de arvore binaria de busca
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include "abb.h"

int main(){
	// Vari�veis para controle da duracao da ordena��o
	int quantidade_entradas=0,
			casos_de_busca=0,
			valor=0,
			maior=0,
			menor=0;

	Arvore abb;

	//printf("Teste abb\n");
	cria_arvore(&abb);
	//printf("arvore iniciada\n");

	/*TIMER*/
	struct timeval start, end;
	long long mtimeDim, mtimeEst, seconds, useconds;

	while(1) {
		cria_arvore(&abb);

		scanf("%d", &quantidade_entradas);
		printf("Quantidade de entradas: %d\n", quantidade_entradas);

		scanf("%d", &casos_de_busca);
		printf("Casos de busca: %d\n", casos_de_busca);

		//Fim da leitura, break while e retorna
		if(quantidade_entradas == 0 && casos_de_busca == 0)
			break;

		elem_t intervalo[quantidade_entradas];

		//printf("Iniciando insercao...\n");
		while(quantidade_entradas > 0) {
			scanf("%d", &valor);
			insere(&abb, valor);
			quantidade_entradas--;
		}

		//printf("no raiz = %d", abb->info);
		printf("\n"); inorder(abb); printf("\n");

		if(verifica(abb)) {
			printf("eh uma arvore de busca\n");
		} else {
			printf("Oops...nao eh uma arvore de busca!!!\n");
		}


		// /*INICIANDO BUSCAS*/
		// printf("insercao terminada, iniciando casos de busca\n");
		for(int i=0; i < casos_de_busca; i++) {
			scanf("%d", &menor);
			scanf("%d", &maior);

			if(menor > maior) {
				int tmp = menor;
				menor = maior;
				maior = tmp;
			}

			printf("\nCaso de busca %d: buscando valores entre %d e %d\n", i+1, menor, maior);
			busca_por_intervalo(abb, menor, maior, intervalo); //decidir retorno da funcao e exibir antes da proxima itera��o do for
		}

		printf("\n");
	}
	return 0;
}
