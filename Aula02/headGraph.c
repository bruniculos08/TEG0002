#include <stdio.h>
#include <stdlib.h>
#include "headGraph.h"

listaDeAdjacencia *createGraph(){
    listaDeAdjacencia *graph;
    graph = NULL;
    int n;
    int a;
    printf("Digite o número de vertices: ");
    scanf("%i", &n);
    for(int i = 0; i < n; i++){
        if(graph == NULL) graph = (listaDeAdjacencia *)malloc(sizeof(listaDeAdjacencia));
        printf("Digite o numero de vertices adjacentes ao vertice v[%i]: ", i+1);
        scanf("%i", &a);
        for(int j = 0; j < a; j++){
            printf("Digite o numero do vertice %i adjacente a v[%i]: ", j+1, i+1);
        }
    }
}