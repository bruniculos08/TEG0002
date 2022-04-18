#include <stdio.h>
#include <stdlib.h>
#include "headGraph.h"

row *createGraph(row *graph, int n){
    row *AuxGraph;
    AuxGraph = graph;
    for(int i = 0; i < n; i++){
        // 1. criando linha da matriz
        if(AuxGraph == NULL){
            AuxGraph = (row *)malloc(sizeof(row));
            AuxGraph->line = NULL;
            AuxGraph->next = NULL;
        }
        int m;
        printf("Numero de vertices adjacentes ao vertice v[%i]: ", i+1);
        scanf("%i", &m);
        AuxGraph->line = (int *)malloc(sizeof(int)*m);
        for(int j = 0; j < m; j++){
            printf("Indice do vertice adjacente %i: ", j);
            scanf("%i", &AuxGraph->line[j]);
        }
    }
    return graph;
}