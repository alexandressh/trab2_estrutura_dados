/*
 * Árvores binárias de busca.
 */

//Adaptado de http://www.geeksforgeeks.org/avl-tree-set-1-insertion/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "arvore_balaceada.h"

int retorneBalanceamento(No *n) {
    return n == NULL ? 0 : n->fatorBalanceamento;
}

int maior(int a, int b) {
    return (a > b)? a : b;
}

void cria_arvore_avl(Arvore_avl *p) {
    *p = NULL;
}

No * novoNo(elem_t valor) {
    struct No* noh = (struct No*) malloc(sizeof(struct No));
    noh->indice = valor;
    noh->esq = NULL;
    noh->dir = NULL;
    noh->fatorBalanceamento = 1; //noh folha, fator balanceamento = 0
    return noh;
}

void percuso_em_ordem_avl(Arvore_avl p) {
    if (p != NULL) {
        percuso_em_ordem_avl(p->esq);
        printf("%d ", p->indice);
        percuso_em_ordem_avl(p->dir);
    }
}

/* Retorna 0 se a chave for repetida */
int insercao_avl(Arvore_avl *p, int chave, int * rot, int * rotDupla) {
	if(*p == NULL) {
		No* noh = novoNo(chave);
		*p = noh;
	} else {
		No* result = _insere(*p, chave, rot, rotDupla);
		if(result == NULL) {
			return 0;
		} else {
			*p = result;
		}
	}
	return 1;
}

No * rotacaoEsquerda(No *pB) {
  No *pA = pB->dir;
  No *aux = pA->esq;

  //Rotacionando
  pA->esq = pB;
  pB->dir = aux;

  //Atualizando fatores de balanceamento
  pB->fatorBalanceamento = maior(retorneBalanceamento(pB->esq), retorneBalanceamento(pB->dir))+1;
  pA->fatorBalanceamento = maior(retorneBalanceamento(pA->esq), retorneBalanceamento(pA->dir))+1;

  return pA;
}

No * rotacaoDireita(No *pA) {
  No *pB = pA->esq;
  No *aux = pB->dir;

  //Rotacionando
  pB->dir = pA;
  pA->esq = aux;

  //Atualizando fatores de balanceamento
  pA->fatorBalanceamento = maior(retorneBalanceamento(pA->esq), retorneBalanceamento(pA->dir))+1;
  pB->fatorBalanceamento = maior(retorneBalanceamento(pB->esq), retorneBalanceamento(pB->dir))+1;

  return pB;
}

No* _insere(No *p, int chave, int * rot, int * rotDupla) {
    if (p == NULL) {
      return novoNo(chave);
    }

    if (chave < p->indice) {
		    p->esq  = _insere(p->esq, chave, rot, rotDupla);
    } else if (chave > p->indice) {
		    p->dir = _insere(p->dir, chave, rot, rotDupla);
    } else { //chave ja existe
		    return NULL;
	  }

    //atualiza balanceamento do pai do no inserido
	   p->fatorBalanceamento = 1 + maior(retorneBalanceamento(p->esq), retorneBalanceamento(p->dir));
	//verifica balanceamento
    int balanceamento = (p == NULL ? 0 : (retorneBalanceamento(p->esq) - retorneBalanceamento(p->dir)));
  	if (balanceamento > 1 && chave < p->esq->indice) { // Left Left Case
          (*rot)++;
          return rotacaoDireita(p);
  	} else if (balanceamento < -1 && chave > p->dir->indice) { // Right Right Case
          (*rot)++;
          return rotacaoEsquerda(p);
  	} else if (balanceamento > 1 && chave > p->esq->indice) { // Left Right Case
          (*rotDupla)++;
          p->esq =  rotacaoEsquerda(p->esq);
          return rotacaoDireita(p);
      } else if (balanceamento < -1 && chave < p->dir->indice) { // Right Left Case
          (*rotDupla)++;
          p->dir = rotacaoDireita(p->dir);
          return rotacaoEsquerda(p);
      } else {
  		    //não precisa balancear
  	  }
    return p;
}

/* Verifica se p é uma árvore de busca */
int verifica_se_eh_arvore_de_busca_avl(Arvore_avl p) {
	return _verifica(p, INT_MIN, INT_MAX);
}

int _verifica(Arvore_avl p, int min, int max) {
	if (p == NULL)
		return 1;
	if (p->indice < min || p->indice > max)
		return 0;

	return _verifica(p->esq, min, p->indice-1) && _verifica(p->dir, p->indice+1, max);
}

int busca_por_intervalo_avl(Arvore_avl p, int min, int max, Fila * fila) {
	if (p != NULL) {
		busca_por_intervalo_avl(p->esq, min, max, fila);

		if(p->indice >= min && p->indice <= max) {
      queue(fila, p->indice);
		}

		busca_por_intervalo_avl(p->dir, min, max, fila);
	}
	return 0;
}

void libera_avl(Arvore_avl p) {
  if (p != NULL) {
      libera_avl(p->esq);
      libera_avl(p->dir);
      free(p);
  }
}
