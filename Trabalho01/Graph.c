#include <stdio.h>
#include <stdlib.h>
#include "headGraph.h"

int main(){
    int n = 0;
    scanf("%i", &n);
    int **matrix = createGraph(n);
    printMatrix(matrix, n, n);
    int p = 0;
    do
    {
        p = 0;
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
