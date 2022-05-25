#include "headImage.h"
#include <stdio.h>
#include <stdlib.h>

int **createMatrix(){
    int rows, columns;

    FILE *filePointer;
    filePointer = fopen("image.txt", "rt");
    fscanf(filePointer, "%i %i \n", rows, columns); 
    
    rows++;
    columns++;

    // (1) Alocando os ponteiros para as linhas da matriz:
    // - o ponteiro de ponteiro aponta para um espaço a partir de onde há um número rows de ponteiros para int's
    int **matrix = (int **)malloc(rows*sizeof(int*));


    // (2) Alocando os ponteiros para as colunas da matriz:
    // - cada ponteiro para int aponta para um espaço a partir de onde há um número columns de int's
    for(int i=0; i<rows; i++){
        matrix[i] = (int *)malloc(columns*sizeof(int));

        // (2.1) Setando os elementos da matriz iguais à zero para inserção (por meio de adição) das arestas na função createGraph:
        for(int j=0; j<columns; j++){
            
            if (i != 0 && j != 0) fscanf(filePointer, "%i ", matrix[i][j]);
            else matrix[i][j] = 0;
        }
        //fscanf(filePointer, "\n"); 
        
    }
    return matrix;
}