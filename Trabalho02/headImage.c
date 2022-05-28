#include "headImage.h"
#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int *mainRows, int *mainCols){
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
    
    fclose(filePointer);
    *mainRows = rows;
    *mainCols = cols;
    printMatrix(matrix, rows, cols);
    return matrix;
}

int **createRegister(){
    int rows, cols; 

    FILE *filePointer;
    filePointer = fopen("image.txt", "rt");
    fscanf(filePointer, "%i %i \n", &rows, &cols);

    rows+=2; cols+=2;

    fclose(filePointer);

    int **matrix = (int **)malloc(rows*sizeof(int*));
    for (int i = 0; i < rows; i++){
        matrix[i] = (int *)malloc(cols*sizeof(int));
        for (int j = 0; j < cols; j++) matrix[i][j] = 0;
    }

    printf("\n");
    printMatrix(matrix, rows, cols);
    return matrix;
}

void printMatrix(int **matrix, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++) printf("%i ", matrix[i][j]);
        printf("\n");
    }
}

int countComponents(int **matrix, int **registers, int rows, int cols){
    int count;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(matrix[i][j] == 1 && registers[i][j] == 0){
                deepSearch(matrix, registers, i, j);
                count++;
            } 
        }
    }
    return count;
}

void deepSearch(int **matrix, int **registers, int row, int col){
    if(matrix[row][col] == 1 && registers[row][col] == 0) registers[row][col] = 1; 
    else if(matrix[row][col] == 0) return;
    deepSearch(matrix, registers, row+1, col);
    deepSearch(matrix, registers, row-1, col);
    deepSearch(matrix, registers, row, col+1);
    deepSearch(matrix, registers, row, col-1);
}