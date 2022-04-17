#include <stdio.h>
#include <stdlib.h>
#include "headGraph.h"

listaDeAdjacencia *createGraph(listaDeAdjacencia *graph, int n){
    listaDeAdjacencia *graphAux;
    graphAux = graph;
    for(int i = 0; i <n; i++){
        if(graphAux == NULL){
            // Criando a primeira linha da matriz de adjacências 
            graphAux = (listaDeAdjacencia *)malloc(sizeof(listaDeAdjacencia));
            graphAux->vertices = NULL;
            graphAux->nextLista = NULL;
        }
        
        // O número de vértices é igual a quantidade de "colunas" da linha
        int nVertices;
        printf("Digite o numero de vertices adjacentes ao vertice v[%i]: ", i);
        scanf("%d", &nVertices);
        
        // Ponteiro para andar pelas colunas da linha
        listaDeVertices *verticesAux;
        verticesAux = graphAux->vertices;

        for(int j = 0; j < nVertices; j++){
            if(verticesAux == NULL){
                verticesAux = (listaDeVertices *)malloc(sizeof(listaDeVertices));
                verticesAux->nextVertice = NULL;
            }
            printf("Digite o indice do vertice %i adjacente a v[%i]: ", j+1, i+1);
            scanf("%i", &verticesAux->indice);
            // Anda para a próxima coluna da linha
            verticesAux = verticesAux->nextVertice;
        }
    }
    return graphAux;
}

int degree(int k, listaDeAdjacencia *graph){
    int result = 0;
    listaDeAdjacencia *graphAux;
    graphAux = graph;
    for(int i = 0; i < k; i++){
        graphAux = graphAux->nextLista;
        printf("Here");
    }
    listaDeVertices *aux = graphAux->vertices;
    while(aux != NULL){
        if(aux->indice = k) result += 2;
        else result += 1;
    }
    return result;
}

