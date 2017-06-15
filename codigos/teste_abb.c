/*
 * Programa para testar as opera��es de arvore binaria de busca
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include "timer.h"
#include "fila.c"
#include "abb.c"
#include "avl.c"

int main(){
	int quantidade_entradas=0,
			casos_de_busca=0,
			valor=0,
			maior=0,
			menor=0,
			i=0;
		int	rot = 0,
			rotDupla = 0;

	double inicio_tempo_abb,
			 fim_tempo_abb,
			 inicio_tempo_avl,
			 fim_tempo_avl;

	Arvore_abb abb;
	Arvore_avl avl;
	Fila filaAbb;
	Fila filaAvl;

	while(1) {
		// cria_arvore_abb(&abb);
		cria_arvore_avl(&avl);
		// initFila(&filaAbb);
		initFila(&filaAvl);

		scanf("%d", &quantidade_entradas);
		scanf("%d", &casos_de_busca);

		if(quantidade_entradas == 0 && casos_de_busca == 0)
			break;

		// GET_TIME(inicio_tempo_abb);
		GET_TIME(inicio_tempo_avl);

		while(quantidade_entradas > 0) {
			scanf("%d", &valor);
			// insercao_abb(&abb, valor);
			insercao_avl(&avl, valor, &rot, &rotDupla);
			quantidade_entradas--;
		}

		// GET_TIME(fim_tempo_abb);
		GET_TIME(fim_tempo_avl);

		// printf("Tempo Inserção %7.6f \n", fim_tempo_abb - inicio_tempo_abb);
		printf("Tempo Inserção %7.6f \n", fim_tempo_avl - inicio_tempo_avl);
		printf("Rotacoes %d - Rotacoes duplas %d \n", rot, rotDupla);


		//percuso_em_ordem_abb(abb);
		//percuso_em_ordem_avl(avl);
		// printf("\n");

		// if(!verifica_se_eh_arvore_de_busca_abb(abb)) {
		// 	return 1;
		// }
		if(!verifica_se_eh_arvore_de_busca_avl(avl)) {
			return 1;
		}

		/*INICIANDO BUSCAS*/
		for(i = 0; i < casos_de_busca; i++) {
			scanf("%d", &menor);
			scanf("%d", &maior);

			if(menor > maior) {
				int tmp = menor;
				menor = maior;
				maior = tmp;
			}

			// GET_TIME(inicio_tempo_abb);
			// busca_por_intervalo_abb(abb, menor, maior, &filaAbb);
			// GET_TIME(fim_tempo_abb);

			GET_TIME(inicio_tempo_avl);
			busca_por_intervalo_avl(avl, menor, maior, &filaAvl);
			GET_TIME(fim_tempo_avl);

			// printf("Tempo busca %7.6f ", fim_busca_abb - inicio_tempo_abb);
			printf("%7.6f\n", fim_tempo_avl - inicio_tempo_avl);

			// if(isVazia(&filaAbb)) {
			// 	printf("0");
			// } else {
			// 	while(!isVazia(&filaAbb)) {
			// 		printf("%d ", pop(&filaAbb));
			// 		pop(&filaAvl);
			// 	}
			// }

			//Nao requerido na especificacao - fila da avl esvaziada juntamente com a da abb
			if(isVazia(&filaAvl)) {
				printf("0");
			} else {
				while(!isVazia(&filaAvl)) {
					pop(&filaAvl);
					// printf("%d ", pop(&filaAvl));
				}
			}
			printf("\n");
		}
		// libera_abb(abb);
		libera_avl(avl);
	}
	return 0;
}
