#include "lista.h"
#include <stdlib.h>

// cria um novo nó p lista de adjacência -> o no guarda o número do vértice de destino e um ponteiro pro próx nó da lista (lista encadeada)
 
No *criarNo(int vertice) {
  // aloca espaço pro novo no
  No *novo = (No *)malloc(sizeof(No));

  // guarda o vértice de destino da aresta
  novo->vertice = vertice;

  // como é o nó mais novo, ainda n aponta p nada
  novo->proximo = NULL;

  return novo;
}

// inicializa o vetor de listas de adjacencia -> cada posicao do vetor representa um vértice do grafo e começa vazia (sem nenhuma aresta)

void inicializarListaAdj(No *lista[]) {
  for (int i = 0; i < MAX_VERTICES; i++) {
    lista[i] = NULL;
  }
}

// libera memória usada pela lista encadeada de adjacência -> percorre a lista nó a no e libera cada um, ate chegar ao final (NULL)

void destruirListaAdj(No **lista) {
  No *atual = *lista;

  while (atual != NULL) {
    No *proximo = atual->proximo; // guarda o próximo antes de liberar o atual
    free(atual);
    atual = proximo;
  }

  // lista agora está vazia
  *lista = NULL;
}