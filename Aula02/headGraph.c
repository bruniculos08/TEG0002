#include <stdio.h>
#include <stdlib.h>
#include "headGraph.h"

listaDeAdjacencia *createGraph(listaDeAdjacencia *graph, int n){
    listaDeAdjacencia *graphAux;
    graphAux = graph;
    for(int i = 0; i <n; i++){
        if(graphAux == NULL){
            graphAux = (listaDeAdjacencia *)malloc(sizeof(listaDeAdjacencia));
            graphAux->vertices = NULL;
        }
        int nVertices;
        printf("Digite o numero de vertices adjacentes ao vertice v[%i]: ", i);
        scanf("%d", &nVertices);
        listaDeVertices *verticesAux;
        verticesAux = graphAux->vertices;
        for(int j = 0; j < nVertices; j++){
            if(verticesAux == NULL){
                verticesAux = (listaDeVertices *)malloc(sizeof(listaDeVertices));
                verticesAux->nextVertice = NULL;
            }
        }
    }
}

int degree(int k, listaDeAdjacencia *graph){
    int result = 0;
    listaDeAdjacencia *graphAux;
    graphAux = graph;
    for(int i = 0; i < k; i++){
        graphAux = graphAux->nextLista;
        printf("Here");
    }
    listaDeVertices *aux = graphAux->vertices;
    while(aux != NULL){
        if(aux->indice = k) result += 2;
        else result += 1;
    }
    return result;
}

