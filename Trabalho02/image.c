#include "headImage.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int rows, cols;
    int **matrix = createMatrix(&rows, &cols);
    int **registers = createRegister();
    printf("Componentes = %i\n", countComponents(matrix, registers, rows, cols));

}