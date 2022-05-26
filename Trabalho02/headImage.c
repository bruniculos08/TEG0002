#include "headImage.h"
#include <stdio.h>
#include <stdlib.h>

int **createMatrix(){
    int rows, cols;

    FILE *filePointer;
    filePointer = fopen("image.txt", "rt");
    fscanf(filePointer, "%i %i \n", &rows, &cols);

    printf("%i rows, %i cols\n", rows, cols);
    rows+=2; cols+=2;

    int **matrix = (int **)malloc(rows*sizeof(int*));
    for (int i = 0; i < rows; i++){
        matrix[i] = (int *)malloc(cols*sizeof(int));
        for (int j = 0; j < cols; j++){
            if (i == 0 || j == 0 || i == rows-1 || j == cols-1) matrix[i][j] = 0;
            else fscanf(filePointer, "%i ", &matrix[i][j]);
        }
        fscanf(filePointer, "\n");
    }
    
    printMatrix(matrix, rows, cols);
    return matrix;
}

void printMatrix(int **matrix, int rows, int columns){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++) printf("%i ", matrix[i][j]);
        printf("\n");
    }
}