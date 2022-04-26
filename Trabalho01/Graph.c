#include <stdio.h>
#include <stdlib.h>
#include "headGraph.h"

int main(){
    int n;
    int **matrix = createGraph(&n);
    int p;
      do {
        do{
          p = 0;
          printf("\n[1]: Imprimir matriz de adjacências");
          printf("\n[2]: Verificar Laços");
          printf("\n[3]: Verificar Grau de cada vértice");
          printf("\n[4]: Verificar Vértices Isolados");
          printf("\n[5]: Verificar Teorema das Arestas");
          printf("\n[6]: Verificar Arestas Múltiplas");
          printf("\n[7]: Exibir número de nós e arestas");
          printf("\n[8]: Exibir soma de todos os graus dos vértices");
          printf("\n[0]: Sair\n\n");
          fflush(stdin);
          scanf("%i", &p);
        }while(p < 0 || p > 8);
          switch (p)
          {
          case 1:
            printf("\n");
              printMatrix(matrix, n, n);
              break;
          case 2:
              lacetes(matrix, n);
              break;
          case 3:
              for(int i = 0; i < n; i++){
                  printf("Grau de v[%i] = %i\n", i+1, degree(i, matrix, n));
              }
              fflush(stdin);
              break;
          case 4:
              verticesIsolados(matrix, n);
              break;
          case 5:
              verificaMaxV(matrix, n);
              break;
          case 6:
              arestasMultiplas(matrix, n);
              printf("\n");
              break;
          case 7:
            printf("Número de nós: %i", n);
            numArestas(matrix, n);
            break;  
          case 8:
            somatorioGraus(matrix, n);
            break;
          default:
            break;
          }
          fflush(stdin);
      } while (p != 0);
      
  printf("\nObrigado por usar nosso programa !!\n");
}