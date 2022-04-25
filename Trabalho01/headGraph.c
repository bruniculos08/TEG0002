#include <stdio.h>
#include <stdlib.h>
#include "headGraph.h"

int **createMatrix(int rows, int columns){

    // (1) Alocando os ponteiros para as linhas da matriz:
    // - o ponteiro de ponteiro aponta para um espaço a partir de onde há um número rows de ponteiros para int's
    int **matrix = (int **)malloc(rows*sizeof(int*));

    // (2) Alocando os ponteiros para as colunas da matriz:
    // - cada ponteiro para int aponta para um espaço a partir de onde há um número columns de int's
    for(int i=0; i<rows; i++){
        matrix[i] = (int *)malloc(columns*sizeof(int));
    }
    return matrix;
}

int **createGraph(int n){
    
    // (1) Criando a matriz do grafo:
    int **matrix = createMatrix(n, n);
    printf("tamanho da matriz = %i\n", sizeof(matrix));
    
    int i = 0;
    int j = 0;
    // (2) Loop de acordo para inserir as arestas:
    do
    {
      scanf("(%i, %i)", &i, &j);  
    } while (i != 0 && j != 0);
    
    return matrix;
}

int degree(int i, int **matrix, int n){
    int g = 0;
    for(int j=0; j<n; j++){
        g += matrix[i][j];
    }
    return g;
}

void printMatrix(int **matrix, int rows, int columns){
    //rows = (sizeof(matrix));
    printf("rows = %i\n", rows);
    //columns = sizeof(matrix[0])/sizeof(matrix[0][0]);
    printf("columns = %i\n", columns);

    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++) printf("%i ", matrix[i][j]);
        printf("\n");
    }
}

void lacetes(int **matrix, int n){
    for(int i=0; i<n; i++){
        if(matrix[i][i] > 0) printf("lacete no vertice v[%i]\n", i);
    }
}

void arestasMultiplas(int **matrix, int n){
     for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(matrix[i][j] > 1 && i != j) printf("aresta multipla entre os vertices v[%i] e v[%i]\n", i, j);
        }
     }
}

void verticesIsolados(int **matrix, int n){
    for(int i=0; i<n; i++){
        if(degree(i, matrix, n) == 0) printf("v[%i] é um vertice isolado\n", i);
    }
}

void verificaMaxV(int **matrix, int n){
    int max = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(i != j && i != j) max += 1;
        }
    }
    if(max == n*(n-1)/2) printf("o numero de arestas esta de acordo com o teorema\n");
    else printf("o numero de arestas nao esta de acordo com o teorema\n");
}