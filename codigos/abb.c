/*
 * Árvores binárias de busca.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "abb.h"

void cria_arvore_abb(Arvore_abb *p) {
    *p = NULL;
}

void percuso_em_ordem_abb(Arvore_abb p) {
    if (p != NULL) {
        percuso_em_ordem_abb(p->esq);
        printf("%d ", p->info);
        percuso_em_ordem_abb(p->dir);
    }
}

/* Retorna 0 se a chave for repetida */
int insercao_abb(Arvore_abb *p, int chave) {
    NoAbb *aux;

    if (*p == NULL) {
		//colocar isso em um metodo 'cria_noh'
        aux =  malloc(sizeof(NoAbb));
        aux->info = chave;
        aux->esq = NULL;
        aux->dir = NULL;

        *p = aux;
        return 1;
    }

    if ((*p)->info > chave) {
        return insercao_abb(&(*p)->esq, chave);
    } else if ((*p)->info < chave) {
        return insercao_abb(&(*p)->dir, chave);
    }

    return 0; // achou
}

/* Verifica se p é uma árvore de busca */
int verifica_se_eh_arvore_de_busca_abb(Arvore_abb p) {
	return _verifica_abb(p, INT_MIN, INT_MAX);
}

int _verifica_abb(Arvore_abb p, int min, int max) {
	if (p == NULL)
		return 1;
	if (p->info < min || p->info > max)
		return 0;

	return _verifica_abb(p->esq, min, p->info-1) && _verifica_abb(p->dir, p->info+1, max);
}

int busca_por_intervalo_abb(Arvore_abb p, int min, int max, Fila * intervalo) {
	if (p != NULL) {
		busca_por_intervalo_abb(p->esq, min, max, intervalo);

		if(p->info >= min && p->info <= max) {
      push(intervalo, p->info);
		}

		busca_por_intervalo_abb(p->dir, min, max, intervalo);
	}
	return 0;
}

void libera_abb(Arvore_abb p) {
  if (p != NULL) {
      libera_abb(p->esq);
      libera_abb(p->dir);
      free(p);
  }
}
