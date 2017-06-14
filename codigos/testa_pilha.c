#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
  Pilha pilha;
  initPilha(&pilha);
  push(&pilha, 8);

  printf("%d\n", pop(&pilha));
}
