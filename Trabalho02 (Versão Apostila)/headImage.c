#include "headImage.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <math.h>

int **createMatrix(int *mainRows, int *mainCols){
    int rows, cols;

    FILE *filePointer;
    filePointer = fopen("image.txt", "rt");
    fscanf(filePointer, "%i %i \n", &rows, &cols);

    printf("%i rows, %i cols\n", rows, cols);
    rows+=2; cols+=2;
    R = rows; C = cols;


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
    printMatrix(matrix);
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
    printMatrix(matrix);
    return matrix;
}

void printMatrix(int **matrix){
    printf("\n\n\n\n");
    for(int i=1; i<R-1; i++){
        printf("                                          ");
        for(int j=1; j<C-1; j++){
           if(matrix[i][j] == 0) printf("%i ", 0);
           else printf("%i ", 1);
        }
        printf("\n");
    }
}

void printComponents(){
    for(int i=0; i<count; i++){
        printf("Componente: %i, Pixels = %i, Coordenadas baricentro: (%i, %i)\n", i+1, lista[i].numeroDePixels, lista[i].baricentroX, lista[i].baricentroY);
    }
}

int countComponents(int **matrix, int **registers){
    count = 0; 
    visitados = 0;
    lista = NULL;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            // (1) Se o pixel atual ainda não foi marcado então este pixel faz parte de um novo componente: 
            if(matrix[i][j] == 1 && registers[i][j] == 0){
                if(lista == NULL) lista = (componente *)malloc(sizeof(componente));
                else lista = realloc(lista, sizeof(componente)*(count+1));
                lista[count].baricentroX = 0;
                lista[count].baricentroY = 0;
                lista[count].numeroDePixels = 0;

                // (1.1) Chamar busca em profundidade para marcar todos os pixels deste componente:
                deepSearch(matrix, registers, i, j);
                // (1.2) Adicionar 1 a quantidade de componentes encontrados:
                

                lista[count].baricentroX = lista[count].baricentroX/lista[count].numeroDePixels -1;
                lista[count].baricentroY = lista[count].baricentroY/lista[count].numeroDePixels -1;

                count++;
            } 
        }
    }
    
    return count;
}

void deepSearch(int **matrix, int **registers, int row, int col){
    
    lista[count].baricentroX += col;
    lista[count].baricentroY += row;
    lista[count].numeroDePixels++;

    // (1) Se o pixel atual é um nó e ainda não foi visitado, registrar pixel atual como visitado.
    if(matrix[row][col] == 1 && registers[row][col] == 0){
        visitados++;
        registers[row][col] = 1;
    }

    system("cls");
    printMatrix(registers);
    usleep(90000);
    
    // (2) Se o pixel atual não é um nó ou já foi visitado não iniciar busca.
    //else if(matrix[row][col] == 0 || registers[row][col] > 0) return; 

    if(matrix[row][col+1] == 1 && registers[row][col+1] == 0){
        visitados++;
        registers[row][col+1] = visitados;
        deepSearch(matrix, registers, row, col+1); // Verifica pixel à direita
    }

    if(matrix[row][col-1] == 1 && registers[row][col-1] == 0){
        visitados++;
        registers[row][col-1] = visitados;
        deepSearch(matrix, registers, row, col-1); // Verifica pixel à esquerda
    }

    if(matrix[row+1][col] == 1 && registers[row+1][col] == 0){
        visitados++;
        registers[row+1][col] = visitados;
        deepSearch(matrix, registers, row+1, col); // Verifica pixel acima
    }

    if(matrix[row-1][col] == 1 && registers[row-1][col] == 0){
        visitados++;
        registers[row-1][col] = visitados;
        deepSearch(matrix, registers, row-1, col); // Verifica pixel abaixo
    }

}

void deepSearchEight(int **matrix, int **registers, int row, int col){

    // (1) Se o pixel atual é um nó e ainda não foi visitado, registrar pixel atual como visitado.
    if(matrix[row][col] == 1 && registers[row][col] == 0) registers[row][col] = 1; 
    
    // (2) Se o pixel atual não é um nó ou já foi visitado não iniciar busca.
    else if(matrix[row][col] == 0 || registers[row][col] == 1) return; 
    
    deepSearchEight(matrix, registers, row+1, col); // Verifica pixel acima
    deepSearchEight(matrix, registers, row-1, col); // Verifica pixel abaixo
    
    deepSearchEight(matrix, registers, row+1, col+1); // Verifica pixel canto superior direito
    deepSearchEight(matrix, registers, row-1, col+1); // Verifica pixel canto inferior direito
    deepSearchEight(matrix, registers, row+1, col-1); // Verifica pixel canto superior esquerdo
    deepSearchEight(matrix, registers, row-1, col-1); // Verifica pixel canto inferior esquerdo
    
    deepSearchEight(matrix, registers, row, col+1); // Verifica pixel à direita
    deepSearchEight(matrix, registers, row, col-1); // Verifica pixel à esquerda
}