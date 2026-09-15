#include "matriz.h"


// funcao q inicializa a matriz de adjacência -> no início o grafo n tem nenhuma aresta, então tds as posições da matriz recebem false

void inicializarMatrizAdj(bool matriz[MAX_VERTICES][MAX_VERTICES]) {
  for (int i = 0; i < MAX_VERTICES; i++) {
    for (int j = 0; j < MAX_VERTICES; j++) {
      matriz[i][j] = false;
    }
  }
}

// insere uma aresta direcionada na matriz de adjacência -> vai do vertice de origem ate o vertice de destino 
// antes de inserir verifica se os índices são válidos (dentro do tamanho da matriz)

bool inserirArestaMatriz(bool matriz[MAX_VERTICES][MAX_VERTICES], int origem, int destino) {
  // verifica se os vértices existem dentro do grafo
  if (origem < 0 || origem >= MAX_VERTICES || destino < 0 || destino >= MAX_VERTICES) {
    return false;
  }

  // marca a existência da aresta origem -> destino
  matriz[origem][destino] = true;

  return true;
}

// verificacao se existe uma aresta direcionada entre dois vertices -> retorna false se os índices informados forem incalidos

bool existeArestaMatriz(bool matriz[MAX_VERTICES][MAX_VERTICES], int origem, int destino) {
  if (origem < 0 || origem >= MAX_VERTICES || destino < 0 || destino >= MAX_VERTICES) {
    return false;
  }

  return matriz[origem][destino];
}