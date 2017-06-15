#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include "fila.c"
#include "avl.c"

int main() {
	// Variáveis para controle da duracao da ordenação
	int quantidade_entradas=0,
			casos_de_busca=0,
			valor=0,
			maior=0,
			menor=0,
			i=0;

	Arvore_avl avl;
	Fila fila;
	//printf("Teste avl\n");
	//printf("arvore iniciada\n");

	/*TIMER*/
	struct timeval start, end;
	long long mtimeDim, mtimeEst, seconds, useconds;

	while(1) {
		cria_arvore_avl(&avl);
		initFila(&fila);
		scanf("%d", &quantidade_entradas);
		printf("Quantidade de entradas: %d\n", quantidade_entradas);

		scanf("%d", &casos_de_busca);
		printf("Casos de busca: %d\n", casos_de_busca);

		//printf("Iniciando insercao...\n");
		//Fim da leitura, break while e retorna
		if(quantidade_entradas == 0 && casos_de_busca == 0)
			break;

		while(quantidade_entradas > 0) {
				scanf("%d", &valor);
				//printf("inserindo valor: %d\n", valor);
				insercao_avl(&avl, valor);
				quantidade_entradas--;
				// printf("no raiz = %d", avl->info);
		}


		printf("\n"); percuso_em_ordem_avl(avl); printf("\n");

		if(verifica_se_eh_arvore_de_busca_avl(avl)) {
			printf("eh uma arvore de busca\n");
		} else {
			printf("Oops...nao eh uma arvore de busca!!!\n");
		}

			/*INICIANDO BUSCAS*/
			//printf("insercao terminada, iniciando casos de busca\n");
		for(i = 0; i < casos_de_busca; i++) {
			scanf("%d", &menor);
			scanf("%d", &maior);

			if(menor > maior) {
				int tmp = menor;
				menor = maior;
				maior = tmp;
			}

			printf("\nCaso de busca %d: buscando valores entre %d e %d\n", i+1, menor, maior);
			busca_por_intervalo_avl(avl, menor, maior, &fila); //decidir retorno da funcao e exibir antes da proxima iteração do for

			while(!isVazia(&fila)) {
				printf("%d ", pop(&fila));
			}
		}

			printf("\n");
			libera_avl(avl);
		}

	return 0;
}
