/*
 * �rvores bin�rias de busca.
 */

#ifndef _AVL
#define MAX 15000

typedef int elem_t;

typedef struct No {
  elem_t info; /* chave */
  struct No *esq, *dir;
  int fatorBalanceamento;
} No;

typedef No * Arvore;

No * novoNo(elem_t valor);

No *arv(elem_t c, No* esq, No* dir);

void cria_arvore(Arvore *p);

void inorder(Arvore p);

/* Retorna 0 se a chave for repetida */
int  insere(Arvore *p, int chave);
No* _insere(No *p, int chave);

/* Verifica se p � uma �rvore de busca */
int verifica(Arvore p);
int _verifica(Arvore p, int min, int max);

/* Retorna todos os nohs com valores entre min e max dentro da �rvore p*/
int busca_por_intervalo(Arvore p, int min, int max, Fila * fila);

/* Fun��es auxiliares */
int retorneBalanceamento(No *n);

int maior(int a, int b);

int retorn_ultima_posicao(elem_t  vetor[]);

void libera(Arvore p);

#endif
