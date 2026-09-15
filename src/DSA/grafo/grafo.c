#include "grafo.h"
#include <stdlib.h>

// cria e inicializa o novo grafo -> aloca memória p estrutura e prepara tanto a lista de adjacencia qnt a matriz de adjacência (grafo sem aresta ainda)

Grafo *criarGrafo() {
  Grafo *g = (Grafo *)malloc(sizeof(Grafo));

  inicializarListaAdj(g->listaAdj);
  inicializarMatrizAdj(g->matrizAdj);

  return g;
}

// coloca uma aresta direcionada no grafo (origem -> destino)
//a aresta é registrada nas duas representações (na matriz marcando a posição como true e na lista criando um novo nó no início 

bool inserirAresta(Grafo *g, int origem, int destino) {
  // tenta inserir na matriz; se os índices forem inválidos, para por aqui
  if (!inserirArestaMatriz(g->matrizAdj, origem, destino)) {
    return false;
  }

  // cria o novo nó representando a aresta na lista de adjacência
  No *novoNo = criarNo(destino);

  // insere o novo nó no início da lista do vértice de origem
  novoNo->proximo = g->listaAdj[origem];
  g->listaAdj[origem] = novoNo;

  return true;
}

// verifica se existe uma aresta direcionada entre dois vértices -> usa a matriz pq a consulta é mais rápida(acesso direto) do que percorrer a lista encadeada

bool existeAresta(Grafo *g, int origem, int destino) {
    return existeArestaMatriz(g->matrizAdj, origem, destino);
}

// libera memória 

void destruirGrafo(Grafo *g) {
  for (int i = 0; i < MAX_VERTICES; i++) {
    destruirListaAdj(&g->listaAdj[i]);
  }

  free(g);
}