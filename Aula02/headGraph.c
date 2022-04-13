#include <stdio.h>
#include <stdlib.h>
#include "headGraph.h"

listaDeAdjacencia *createGraph(){
    listaDeAdjacencia *graph;
    graph = NULL;
    listaDeAdjacencia *listaAux;
    listaAux = graph;
    int n;
    int a;
    printf("Digite o numero de vertices: ");
    scanf("%i", &n);
    for(int i = 0; i < n; i++){
        if(listaAux == NULL) listaAux = (listaDeAdjacencia *)malloc(sizeof(listaDeAdjacencia));
        listaAux->vertices = NULL;
        listaAux->next = NULL;
        printf("Digite o numero de vertices adjacentes ao vertice v[%i]: ", i+1);
        scanf("%i", &a);
        listaDeVertices *aux;
        aux = listaAux->vertices;
        for(int j = 0; j < a; j++){
            if(aux == NULL) aux = (listaDeVertices *)malloc(sizeof(listaDeVertices));
            aux->next = NULL;
            printf("Digite o numero do vertice %i adjacente a v[%i]: ", j+1, i+1);
            scanf("%i", &aux->indice);
            aux = aux->next;
        }
        listaAux = listaAux->next;
    }
    return graph;
}

int degree(int k, listaDeAdjacencia *graph){
    int result = 0;
    listaDeAdjacencia *graphAux;
    graphAux = graph;
    for(int i = 0; i < k; i++){
        graphAux = graphAux->next;
        printf("Here");
    }
    listaDeVertices *aux = graphAux->vertices;
    while(aux != NULL){
        if(aux->indice = k) result += 2;
        else result += 1;
    }
    return result;
}

