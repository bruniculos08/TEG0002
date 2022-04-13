#include <stdio.h>
#include <stdlib.h>
#include "headGraph.h"

int main(){
    listaDeAdjacencia *graph = createGraph();
    printf("%i\n", degree(1, graph));
}