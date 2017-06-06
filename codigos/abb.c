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

/* Retorna 1 se a chave for encontrada */
int busca (Arvore p, int chave) {
    if (p == NULL)
        return 0;

    if (p->info > chave)
        return busca(p->esq, chave);
    else if (p->info < chave)
        return busca(p->dir, chave);

    return 1; // achou
}

/* Retorna 1 se a chave for encontrada */
int n_rec_busca(Arvore p, int chave) {
    while (p == NULL) {
        if (p->info > chave)
            p = p->esq;
        else if (p->info < chave)
            p = p->dir;
        return 1; // achou
    }

    return 0;
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

/* Retorna 0 se a chave for repetida */
/* Versão não recursiva */
int  n_rec_insere(Arvore *p, int chave) {
	return;
}


/* Retorna 0 se a chave não for encontrada */
int remove_arv(Arvore *p, int chave) {
    No* rem;
    No** aux;

    if (*p == NULL)
        return 0;

    if ((*p)->info > chave) {
        return remove_arv(&(*p)->esq, chave);
    } else if ((*p)->info < chave) {
        return remove_arv(&(*p)->dir, chave);
    } else { // encontrou

        rem = *p;

        if ((*p)->dir == NULL) {
            *p = (*p)->esq;
        } else if ((*p)->esq == NULL) {
            *p = (*p)->dir;
        } else {
            aux = &(*p)->dir;
            while ((*aux)->esq != NULL)
                aux = &(*aux)->esq;
            *p = *aux;
	    *aux = (*aux)->dir;
            (*p)->esq = rem->esq;
            (*p)->dir = rem->dir;
        }

        free(rem);
        rem = NULL;

        return 1;
    }
}

/* Verifica se p é uma árvore de busca */
int _verifica(Arvore p, int min, int max);
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

int busca_por_intervalo(Arvore p, int min, int max) {
	if (p != NULL) {
		busca_por_intervalo(p->esq, min, max);
		if(p->info >= min && p->info <= max) {
			printf("%d ", p->info);
			//return p->info; //encontrar uma forma de retornar para o main ao invez de apenas printar os valores (armazenar em uma pilha ou fila)
		}
		busca_por_intervalo(p->dir, min, max);
	}
	return 0;
}
