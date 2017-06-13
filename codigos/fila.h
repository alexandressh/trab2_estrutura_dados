#ifndef _FILA

#define MAX 15000
typedef int elem_t;

typedef struct Fila {
	elem_t valor[MAX];
	int inicio;
	int fim;
}Fila;

elem_t pop(Fila * fila);
void push(Fila * fila, elem_t elem);
void initFila(Fila * fila);
int isVazia(Fila * fila);

#endif
