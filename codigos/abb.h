/*
 * Árvores binárias de busca.
 */

#ifndef _ABB

typedef int elem_t;

typedef struct No {
  elem_t info; /* chave */
  struct No *esq, *dir;
} No;

typedef No* Arvore;

void cria_arvore(Arvore *p);

No *arv(elem_t c, No* esq, No* dir);

void inorder(Arvore p);

/* Retorna 1 se a chave for encontrada */
int busca (Arvore p, int chave);

/* Retorna 1 se a chave for encontrada */
int n_rec_busca(Arvore p, int chave);

/* Retorna 0 se a chave for repetida */
int  insere(Arvore *p, int chave);

/* Retorna 0 se a chave for repetida */
/* Versão não recursiva */
int  n_rec_insere(Arvore *p, int chave);

/* Retorna 0 se a chave não for encontrada */
int remove_arv(Arvore *p, int chave);

/* Verifica se p é uma árvore de busca */
int verifica(Arvore p);

/* Verifica se p é uma árvore de busca */
int n_rec_verifica(Arvore p);

/* Retorna todos os nohs com valores entre min e max dentro da árvore p*/
int busca_por_intervalo(Arvore p, int min, int max);

#endif
