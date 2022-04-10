#include <stdio.h>
#include <stdlib.h>

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
    int **matrix = createMatrix(n, n);
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            printf("e[%i][%i] = ", i+1, j+1);
            scanf("%i", &matrix[i][j]);
            // Caso seja uma laço (em grafo não orientado):
            if(i == j && matrix[i][j] == 1){
                matrix[i][j] = 2;
            }
            matrix[j][i] = matrix[i][j];
        }
    }
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

void verificaMaxA(int **matrix, int n){
    int max = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(i != j && i != j) max += 1;
        }
    }
    if(max == n*(n-1)/2) printf("o numero de arestas esta de acordo com o teorema\n");
    else printf("o numero de arestas nao esta de acordo com o teorema\n");
}

int main(){
    int n = 0;
    scanf("%i", &n);
    int **matrix = createGraph(n);
    printMatrix(matrix, n, n);
    int p = 0;
    do
    {
        scanf("%i", &p);
        switch (p)
        {
        case 1:
            lacetes(matrix, n);
            break;
        case 2:
            for(int i = 0; i < n; i++){
                printf("d(v[%i]) = %i\n", i+1, degree(i, matrix, n));
            }
            break;
        case 3:
            verticesIsolados(matrix, n);
            break;
        case 4:
            verificaMaxV(matrix, n);
            break;
        case 5:
            arestasMultiplas(matrix, n);
            break;
        default:
            if(p != 0) printf("Opcao invalida\n");
            break;
        }
    } while (p != 0);
    
}
