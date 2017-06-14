/*
 * Árvores binárias de busca.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "abb.h"

#define MAX 15000


No *arv(elem_t c, No *esq, No *dir) {
    No* aux = malloc(sizeof(No));

    aux->info = c;
    aux->esq = esq;
    aux->dir = dir;

    return aux;
}

void cria_arvore(Arvore *p) {
    *p = NULL;
}

void inorder(Arvore p) {
    if (p != NULL) {
        inorder(p->esq);
        printf("%d ", p->info);
        inorder(p->dir);
    }
}

/* Retorna 0 se a chave for repetida */
int insere(Arvore *p, int chave) {
    No *aux;

    if (*p == NULL) {
		//colocar isso em um metodo 'cria_noh'
        aux =  malloc(sizeof(No));
        aux->info = chave;
        aux->esq = NULL;
        aux->dir = NULL;

        *p = aux;
        return 1;
    }

    if ((*p)->info > chave) {
        return insere(&(*p)->esq, chave);
    } else if ((*p)->info < chave) {
        return insere(&(*p)->dir, chave);
    }

    return 0; // achou
}

/* Verifica se p é uma árvore de busca */
int verifica(Arvore p) {
	return _verifica(p, INT_MIN, INT_MAX);
}

int _verifica(Arvore p, int min, int max) {
	if (p == NULL)
		return 1;
	if (p->info < min || p->info > max)
		return 0;

	return _verifica(p->esq, min, p->info-1) && _verifica(p->dir, p->info+1, max);
}

int busca_por_intervalo(Arvore p, int min, int max, Fila * intervalo) {
	if (p != NULL) {
		busca_por_intervalo(p->esq, min, max, intervalo);

		if(p->info >= min && p->info <= max) {
      push(intervalo, p->info);
		}

		busca_por_intervalo(p->dir, min, max, intervalo);
	}
	return 0;
}


int retorn_ultima_posicao(elem_t vetor []) {
   /*int tam = (int) sizeof(vetor);
  for(int i = 0; i < tam; i++) {
    if(vetor[i] == NULL) {
      return i;
    }
  }*/
  return 0;
}
