#include <stdio.h>
#include <stdlib.h>

typedef struct Graph graph;
struct Graph {
    char name;
    int degree;
    graph **edges;
    // Obs.: note que o grau indica o tamanho da lista edges.
};

int main(){

    // 01. criando um vértice isolado 'a':
    graph *a = (graph *)malloc(sizeof(graph));
    a->name = 'a';
    int degree = 0;
    a->edges = NULL;

    // 02. adicionando uma aresta para e criando simultâneamente um vértice 'b':
    a->edges = (graph **)malloc(sizeof(graph *));
    a->edges[0] = (graph *)malloc(sizeof(graph));
    a->edges[0]->name = 'b';
    a->edges[0]->degree = 1;


    // 03. adiconando uma aresta de 'b' para 'a' (a anteriormente criada era de 'a' para 'b'):
    a->edges[0]->edges = (graph **)malloc(sizeof(graph *));
    a->edges[0]->edges[0] = (graph *)malloc(sizeof(graph));
    a->edges[0]->edges[0] = a;
    // - Obs.: para grafos não orientados pode se ter uma função que cria uma aresta de 'a' para 'b' e uma aresta...
    // ... de 'b' para 'a' mantendo a possibilidade de ida e volta presente em todas as arestas de grafos não orientados.


    printf("%c\n", a->edges[0]->edges[0]->name);
}