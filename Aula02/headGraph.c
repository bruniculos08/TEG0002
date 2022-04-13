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
        if(graph == NULL) graph = (listaDeAdjacencia *)malloc(sizeof(listaDeAdjacencia));
        graph->vertices = NULL;
        graph->next = NULL;
        printf("Digite o numero de vertices adjacentes ao vertice v[%i]: ", i+1);
        scanf("%i", &a);
        listaDeVertices *aux;
        aux = graph->vertices;
        for(int j = 0; j < a; j++){
            if(aux == NULL) aux = (listaDeVertices *)malloc(sizeof(listaDeVertices));
            aux->next = NULL;
            printf("Digite o numero do vertice %i adjacente a v[%i]: ", j+1, i+1);
            scanf("%i", &aux->indice);
            aux = aux->next;
        }
        graph = graph->next;
    }
}