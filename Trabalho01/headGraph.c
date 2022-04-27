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

        // (2.1) Setando os elementos da matriz iguais à zero para inserção (por meio de adição) das arestas na função createGraph:
        for(int j=0; j<columns; j++) matrix[i][j] = 0;
    }
    return matrix;
}

int **createGraph(int *n){
    FILE *filePointer;
    filePointer = fopen("GraphInfo.txt", "rt");
    fscanf(filePointer, "%i \n", n); 
    //printf("%i\n", *n);
    
    // (1) Criando a matriz de adjacência do grafo:
    int **matrix = createMatrix(*n, *n);

    // (2) Loop de acordo para inserir as arestas:
    int i, j;
    do
    {
      // (2.1) Ler linha de aresta e pular para a próxima linha do arquivo:
      fscanf(filePointer, "(%i, %i) \n", &i, &j);

      // (2.2) Há a adição nos elementos simétricos da matriz (tendo em vista que a matriz é simétrica):
      if(i != j){
          matrix[i-1][j-1] += 1;
          matrix[j-1][i-1] += 1;
      }
      else matrix[i-1][j-1] += 1;
      
    } while (!feof(filePointer));
    return matrix;
}

void saveGraph(int **matrix, int n){
    
}

int degree(int i, int **matrix, int n){
    int g = 0;
    for(int j=0; j<n; j++){
        if(i == j) g += 2*(matrix[i][j]);
        else g += matrix[i][j];
    }
    return g;
}

void printMatrix(int **matrix, int rows, int columns){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++) printf("%i ", matrix[i][j]);
        printf("\n");
    }
}

void lacetes(int **matrix, int n){
    // (1) Percorrer apenas na diagonal principal da matriz pois esses elementos representam possíveis arestas de laço:
    for(int i=0; i<n; i++){
        if(matrix[i][i] > 0) printf("Um lacete ou mais no vertice v[%i]\n", i+1);
    }
}

void arestasMultiplas(int **matrix, int n){
     for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(matrix[i][j] > 1) printf("Uma aresta multipla ou mais entre os vertices v[%i] e v[%i].\n", i, j);
        }
     }
}

void verticesIsolados(int **matrix, int n){
    for(int i=0; i<n; i++){
        if(degree(i, matrix, n) == 0) printf("v[%i] é um vertice isolado.\n", i+1);
    }
}

void verificaMaxV(int **matrix, int n){
    int max = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(i != j && i != j) max += 1;
        }
    }
    if(max == n*(n-1)/2) printf("O numero de arestas esta de acordo com o teorema.\n");
    else printf("O numero de arestas nao esta de acordo com o teorema.\n");
}

void numArestas(int **matrix, int n){
  int arestas = 0;
  
  for(int i = 0; i < n; i++){
    for(int j = i; j < n; j ++){
        if(i == j) arestas += 2*(matrix[i][j]);
        else arestas += matrix[i][j];
        for(int k = 0; k < matrix[i][j]; k++) printf("%i %i\n", i+1, j+1);
        
    }
  }

  printf("\nNúmero de Arestas: %i\n",arestas);
}

void somatorioGraus(int **matrix, int n){
  int somatorio = 0;
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == j) somatorio += 2*(matrix[i][j]);
      else somatorio += matrix[i][j];
    }
  }
  printf("\nSomatório dos graus da matriz: %i\n",somatorio);
}