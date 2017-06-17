/*
 * �rvores bin�rias de busca.
 */

#ifndef _ABB

typedef int elem_t;

typedef struct NoAbb {
  elem_t indice; /* chave */
  struct NoAbb *esq, *dir;
} NoAbb;

typedef NoAbb * Arvore_abb;

void cria_arvore_abb(Arvore_abb *p);

void percuso_em_ordem_abb(Arvore_abb p);

/* Retorna 0 se a chave for repetida */
int insercao_abb(Arvore_abb *p, int chave);

/* Verifica se p � uma �rvore de busca */
int verifica_se_eh_arvore_de_busca_abb(Arvore_abb p);
int _verifica_abb(Arvore_abb p, int min, int max);

/* Retorna todos os nohs com valores entre min e max dentro da �rvore p*/
//int busca_por_intervalo(Arvore p, int min, int max, elem_t intervalo []);
int busca_por_intervalo_abb(Arvore_abb p, int min, int max, Fila * intervalo);

void libera_abb(Arvore_abb p);

#endif
