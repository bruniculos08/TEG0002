#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headGraph.h"

row *createGraph(row *graph, int n){
    if(graph == NULL){
        graph = (row *)malloc(sizeof(row));
        graph->line = NULL;
        graph->next = NULL;
    }
    row *AuxGraph;
    AuxGraph = graph;
    for(int i = 0; i < n; i++){
        // (1) criando linha da matriz:
        if(AuxGraph == NULL){
            AuxGraph = (row *)malloc(sizeof(row));
            AuxGraph->line = NULL;
            AuxGraph->next = NULL;
        }

        // (2) criando vetor de tamanho m para a linha:
        int m;
        printf("Numero de vertices adjacentes ao vertice v[%i]: ", i+1);
        scanf("%i", &m);
        AuxGraph->line = (int *)malloc(sizeof(int)*m);

        // (3) adicionando índices em cada item da linha:
        for(int j = 0; j < m; j++){
            printf("Indice do vertice adjacente %i: ", j);
            scanf("%i", &AuxGraph->line[j]);
        }
        AuxGraph = AuxGraph->next;
    }
    return graph;
}

int degree(row *graph, int index){
    row *AuxGraph;
    AuxGraph = graph;

    // (1) Andar até a linha do vértice desejado:
    for(int i = 0; i < index-1; i++){
        AuxGraph = AuxGraph->next;
    }

    // (2) m igual ao número de vértices adjacentes (tamanho do vetor de índices):
    int m = sizeof(AuxGraph->line)/sizeof(AuxGraph->line[0]);
    int d = 0;

    // (3) Andar pelo vetor de vértices adjacentes, aumentando em 1 o valor do grau exceto caso seja laço (em que grau aumentará em 2):
    for(int i = 0; i < m; i++){
        if(AuxGraph->line[i] == index) d += 2;
        else d += 1;
    }
    return d;
}