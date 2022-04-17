#include <stdio.h>
#include <stdlib.h>
#include "headGraph.h"

listaDeAdjacencia *createGraph(listaDeAdjacencia *graph, int n){
    graph = createRows(graph, n);
    listaDeAdjacencia *AuxGraph;
    AuxGraph = graph;
    for(int i = 0; i < n; i++){
        int k;
        printf("Digite o numero de vertices adjacentes ao vertice %i: ", i+1);
        scanf("%i", &k);
        if(k != 0) AuxGraph->vertices = createColumns(AuxGraph->vertices, k, i+1);
    }
    return graph;
}

int degree(int k, listaDeAdjacencia *graph){
    int result = 0;
    listaDeAdjacencia *graphAux;
    graphAux = graph;
    printf("Here\n");
    for(int i = 0; i < k; i++){
        graphAux = graphAux->nextLista;
        printf("Here 1\n");
    }
    listaDeVertices *aux;
    aux = graphAux->vertices;
    while(aux != NULL){
        printf("Here 2\n");
        if(aux->indice = k) result += 2;
        else result += 1;
    }
    printf("Here 3\n");
    return result;
}

listaDeAdjacencia *createRows(listaDeAdjacencia *Rows, int n){
    listaDeAdjacencia *AuxRows;
    AuxRows = Rows;
    for(int i = 0; i < n; i++){
        if(AuxRows == NULL){
            AuxRows = (listaDeAdjacencia *)malloc(sizeof(listaDeAdjacencia));
            AuxRows->nextLista = NULL;
            AuxRows->vertices = NULL;
            printf("Here\n");
        }
        AuxRows = AuxRows->nextLista;
    }
    return Rows;
}

listaDeVertices *createColumns(listaDeVertices *Columns, int k, int v){
    listaDeVertices *AuxColumns;
    AuxColumns = Columns;
    for(int i = 0; i < k; i++){
        if(AuxColumns == NULL){
            AuxColumns = (listaDeVertices *)malloc(sizeof(listaDeVertices));
            AuxColumns->nextVertice == NULL;
            printf("Digite o indice do vertice %i adjacente ao vertice v[%i]: ", i+1, v);
            scanf("%i", &AuxColumns->indice);
        }
    }
    return Columns;
}