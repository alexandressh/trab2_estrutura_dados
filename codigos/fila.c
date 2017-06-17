#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void initFila(Fila * fila) {
	fila->fim = 0;
	fila->inicio = 0;
}
void queue(Fila * fila, elem_t elem) {
	if(fila->fim < MAX) {
		fila->valor[fila->fim] = elem;
		fila->fim++;
	}
}

elem_t dequeue(Fila * fila) {
	if(fila->inicio < fila->fim) {
		return fila->valor[fila->inicio++];
	}
	return -1;
}

int isVazia(Fila * fila) {
	if(fila->fim == fila->inicio) {
		return 1;
	}
	return 0;
}
