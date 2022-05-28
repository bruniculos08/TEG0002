#include "headImage.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int rows, cols;
    int **matrix = createMatrix(&rows, &cols);
    printf("\n");
    int **registers = createRegister();
    printf("\n");
    printf("Componentes = %i\n", countComponents(matrix, registers));

}