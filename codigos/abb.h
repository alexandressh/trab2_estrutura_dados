/*
 * �rvores bin�rias de busca.
 */

#ifndef _ABB

typedef int elem_t;

typedef struct No {
  elem_t info; /* chave */
  struct No *esq, *dir;
} No;

typedef struct NoFila {
  elem_t info; /* chave */
  struct NoFila *prox;
} NoFila;

typedef No* Arvore;

No *arv(elem_t c, No* esq, No* dir);

void cria_arvore(Arvore *p);

void inorder(Arvore p);

/* Retorna 0 se a chave for repetida */
int insere(Arvore *p, int chave);

/* Verifica se p � uma �rvore de busca */
int verifica(Arvore p);
int _verifica(Arvore p, int min, int max);

/* Retorna todos os nohs com valores entre min e max dentro da �rvore p*/
//int busca_por_intervalo(Arvore p, int min, int max, elem_t intervalo []);
int busca_por_intervalo(Arvore p, int min, int max, Fila * intervalo);

int retorn_ultima_posicao(elem_t  vetor[]);

#endif
