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
        for(int j=0; j<n; j++){
            printf("a[%i][%i] = ", i+1, j+1);
            scanf("%i", &matrix[i][j]);
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

int main(){
    int n = 0;
    scanf("%i", &n);
    int **matrix = createGraph(n);
    for(int i=0; i<n; i++){
        printf("d(v[%i]) = %i\n", i, degree(i, matrix, n));
    }
}
