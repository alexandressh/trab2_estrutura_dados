#ifndef _FILA

#define MAX 99999
typedef int elem_t;

typedef struct Fila {
	elem_t valor[MAX];
	int inicio;
	int fim;
}Fila;

elem_t dequeue(Fila * fila);
void queue(Fila * fila, elem_t elem);
void initFila(Fila * fila);
int isVazia(Fila * fila);

#endif
