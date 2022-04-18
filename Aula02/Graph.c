#include <stdio.h>
#include <stdlib.h>
#include "headGraph.h"

int main(){
    row *graph;
    graph = NULL;
    int n;
    printf("Digite o numero de vertices do grafo: ");
    scanf("%i", &n);
    graph = createGraph(graph, n);
}