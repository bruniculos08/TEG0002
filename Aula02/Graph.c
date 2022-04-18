#include <stdio.h>
#include <stdlib.h>
#include "headGraph.h"

int main(){
    row *graph;
    graph = NULL;
    graph = createGraph(graph, 2);
    printf("Here 4\n");
    printf("%i\n", graph->line[0]);
    printf("%i\n", degree(graph, 1));
}