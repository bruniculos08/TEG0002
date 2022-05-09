#include <stdio.h>
#include <stdlib.h>
#include "headGraph.h"

// (0) Função para criar uma matriz qualquer:
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

// (1) Função para criar um grafo (utilizando a função "createMatrix"):
int **createGraph(int *n){
    FILE *filePointer;
    filePointer = fopen("GraphInfo.txt", "rt");
    fscanf(filePointer, "%i \n", n); 
    
    // (1) Criando a matriz de adjacência do grafo:
    int **matrix = createMatrix(*n, *n);

    if(feof(filePointer)) return matrix;

    // (2) Loop de acordo para inserir as arestas:
    int i, j;
    do
    {
      // (2.1) Ler linha de aresta e pular para a próxima linha do arquivo:
      fscanf(filePointer, "%i %i \n", &i, &j);

      // (2.2) Há a adição nos elementos simétricos da matriz (tendo em vista que a matriz é simétrica):
      if(i != j){
          matrix[i-1][j-1] += 1;
          matrix[j-1][i-1] += 1;
      }
      else matrix[i-1][j-1] += 1;
      
    } while (!feof(filePointer));
    fclose(filePointer);
    return matrix;
}

// (2) Função para salvar o grafo (atualmente sendo executado pelo programa) em um arquivo de texto:
void saveGraph(int **matrix, int n){
    remove("GraphInfo.txt");
    FILE *filePointer;
    filePointer = fopen("GraphInfo.txt", "w+");
    fprintf(filePointer, "%i", n);
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            for(int k = 0; k < matrix[i][j]; k++){
                fprintf(filePointer, "\n%i %i", i+1, j+1);
            }
        }
    }
    fclose(filePointer);
}

// (3) Função para calcular o grau (número de arestas incidêntes) em um vértice:
int degree(int i, int **matrix, int n){
    int g = 0;
    for(int j=0; j<n; j++){
        if(i == j) g += 2*(matrix[i][j]);
        else g += matrix[i][j];
    }
    return g;
}

// (4) Função para imprimir a matriz:
void printMatrix(int **matrix, int rows, int columns){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++) printf("%i ", matrix[i][j]);
        printf("\n");
    }
}

// (5) Função para indicar a existência e quais são os lacetes no grafo:
void loops(int **matrix, int n){
  int k = 0;
    // (1) Percorrer apenas na diagonal principal da matriz pois esses elementos representam possíveis arestas de laço:
    for(int i=0; i<n; i++){
        if(matrix[i][i] > 0){
          printf("%i lacete(s) no vertice v[%i]\n", matrix[i][i], i+1);
          k += matrix[i][i];
        }
    }
    if (k ==0) printf("Não há lacetes no grafo.\n");
    else printf("Há %i lacete(s) no grafo.\n", k);
}

// (6) Função para indicar a existência e quais são as arestas multiplas no grafo:
void multipleEdges(int **matrix, int n){
     int k = 0;
     for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(matrix[i][j] > 1){
              printf("%i aresta múltipla entre os vértices v[%i] e v[%i].\n", matrix[i][j]-1, i+1, j+1);
              k += matrix[i][j]-1;
            }
        }
     }
     if (k == 0) printf("Não há arestas múltiplas no grafo.\n");
      else printf("Há %i aresta(s) multiplas no grafo.\n", k);
}

// (7) Função para indicar a existência e quais são os vértices isolados no grafo:
void isolatedVertices(int **matrix, int n){
    int k = 0;
    for(int i=0; i<n; i++){
        int g = 0;
        for(int j=0; j<n; j++){
          if(matrix[i][j] > 0 && i != j) g++;
        }
        if(g == 0){
          printf("v[%i] é um vertice isolado.\n", i+1);
          k++;
        }
    }
    if(k == 0) printf("Não há vértices isolados no grafo.\n");
    else printf("Há %i vértice(s) isolado(s) no grafo.\n", k);
}

// (8) Função para verificar se o número máximo de vértices no grafo (considerando um garfo simples) condiz com a combinção dos n vértices, 2 à 2:
void maximumOfEdges(int **matrix, int n){
    int max = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(i != j && i != j) max += 1;
        }
    }
    if(max == n*(n-1)/2) printf("O numero de arestas esta de acordo com o teorema.\n");
    else printf("O numero de arestas nao esta de acordo com o teorema.\n");
}

// (9) Função para indicar o número de arestas grafo:
void numberOfEdges(int **matrix, int n){
  int arestas = 0;
  printf("Arestas:\n");
  for(int i = 0; i < n; i++){
    for(int j = i; j < n; j ++){
        if(i == j) arestas += 2*(matrix[i][j]);
        else arestas += matrix[i][j];
        for(int k = 0; k < matrix[i][j]; k++) printf("%i %i\n", i+1, j+1);
        
    }
  }

  printf("\nNúmero de Arestas: %i\n",arestas);
}

// (10) Função para indicar o resultado da soma dos graus de todos os vértices no grafo:
void degreeSum(int **matrix, int n){
  int somatorio = 0;
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == j) somatorio += 2*(matrix[i][j]);
      else somatorio += matrix[i][j];
    }
  }
  printf("\nSomatório dos graus da matriz: %i\n",somatorio);
}

// (11) Função para remover um vértice (e por consequência todas as arestas ligadas ao mesmo) de um grafo:
// - Pode se dizer que o grafo é transformado em um subgrafo induzido pelos vértices existentes anteriormente, exceto pelo vértice removido.
int **removeVertice(int **matrix, int *n){
    int m = (*n) - 1;
    int indice;
    printf("Digite o número do vértice que se deseja remover: ");
    scanf("%i", &indice);
    int **newMatrix = createGraph(&m);
    for(int i = 0, k = 0; i < *n && k < m-1; i++){
        if(i == indice-1) i++;
        for(int j = 0, l = 0; j < *n && l < m-1; j++){
            if(j == indice-1) j++;
            newMatrix[k][l] = matrix[i][j];
            l++;
        }
        k++;
    }
    return newMatrix;
}

// (12) Função para remover uma aresta do grafo:
int **removeEdges(int **matrix, int n){
    int r, i, j;
    printf("Digite o número de arestas a serem removidas: ");
    scanf("%i", &r);
    for(int k = 0; k < r; k++){
        printf("Digite uma aresta a ser removida: ");
        do {
            scanf("%i %i", &i, &j);
        } while(i > n || j > n);
        if(matrix[i-1][j-1] > 0) matrix[i-1][j-1] --;
        matrix[j-1][i-1] = matrix[i-1][j-1];
    }
    return matrix;
}

// (13) Função para verificar se o teorema do aperto de mão ("hand shake theorem") é válido para o grafo em questão:
// - Obviamente tal teorema sempre será válido (se não estiver há então algo de errado no código).
void handShake(int **matrix, int n) {
  int grauImpar = 0;
  for (int i = 0; i < n; i++) {
    if (degree(i, matrix, n) % 2 != 0)
      grauImpar++;
  }

  printf("\nNúmero de vértices com grau ímpar: %i", grauImpar);
  if (grauImpar % 2 == 0)
    printf("\nO teorema é satisfeito !\n");
  else
    printf("\nO teorema não é satisfeito !\n");
}

// (14) Função para verificar se o grafo em execução é um grafo simples (sem laços e/ou arestas múltiplas):
void simpleGraph(int **matrix, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] > 1) {
        printf("\nO grafo não é simples !!\n");
        return;
      }
    }
  }
  printf("\nO grafo é simples !!\n");
}

// (15) Função para verificar se o grafo é regular, ou seja, se todos os vértices tem o mesmo grau:
void regularGraph(int **matrix, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (degree(i, matrix, n) != degree(j, matrix, n)) {
        printf("\nO grafo não é regular !!\n");
        return;
      }
    }
  }
  printf("\nO grafo é regular !!\n");
}

// (16) Função para verificar se o grafo é completo, ou seja, se é (ou contém) um grafo simples (com o mesmo número de vértices)...
// ... com o número máximo de arestas:
void completeGraph(int **matrix, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        if (matrix[i][j] != 0) {
          printf("\nO grafo não é completo !!\n");
          return;
        }
      if (matrix[i][j] != 1 && i != j) {
        printf("\nO grafo não é completo !!\n");
        return;
      }
    }
  }
  printf("\nO grafo é completo !!\n");
}

// (17) Função para indicar um passeio de comprimento k a partir de um vértice v no grafo:
void tour(int **matrix, int n, int c) {

  int i, aux;
  for (int i = 0; i < n; i++) {
    aux += degree(i, matrix, n);
  }
  if (aux == 0) {
    printf("\nMatriz nula");
  }
  if (c <= aux) {
    printf("\nO caminho é possível e não são repetidas as arestas\n");
  } else {
    printf("\nO caminho é possível se repetirem arestas\n");
  }
}