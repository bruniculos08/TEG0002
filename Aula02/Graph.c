#include <stdio.h>
#include <stdlib.h>
#include "headGraph.h"

int main(){
    listaDeAdjacencia *graph;
    graph = NULL;
    graph = createGraph(graph);
    printf("%i\n", degree(1, graph));
}