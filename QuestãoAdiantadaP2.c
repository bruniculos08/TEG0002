#include "stdio.h"

typedef struct Marca marca;
typedef struct Fila fila;

struct Fila{
    int vertice;
    fila *proximo;
};

struct Marca{
    int verticeAntecessor;
    int deltaFluxo;
};

int const inf = 100000000000;

int main(){

}

int **zeraMatriz(int **matriz, int n){}

int min(int a, int b){
    if(a < b) return a; 
    else return b;
}

int fordFulkerson(int **W, int n, int **C, int **fluxo){
    fluxo = zeraMatriz(fluxo, n);
    marca vetorDeMarcas[n];
    int vetorVisitados[n];
    
    for(int i=0; i<n; i++){
        vetorDeMarcas[i].verticeAntecessor = -1;
        vetorDeMarcas[i].deltaFluxo = 0;
        vetorVisitados[i] = 0;
    }
    
    do{
        vetorDeMarcas[0].deltaFluxo = inf; 

        for (int i = 0; i < n; i++){
            if((vetorDeMarcas[i].verticeAntecessor != -1 || vetorDeMarcas[i].deltaFluxo != 0) && vetorVisitados[i] == 0){
                for(int j = 0; j < n; j++){
                    if((vetorDeMarcas[j].verticeAntecessor != -1 || vetorDeMarcas[j].deltaFluxo != 0) && W[i][j] != 0){    
                        if(W[i][j] == 1 && fluxo[i][j] < C[i][j]){
                            vetorDeMarcas[j].verticeAntecessor = i;
                            vetorDeMarcas[j].deltaFluxo = min(vetorDeMarcas[i].deltaFluxo, C[i][j]-fluxo[i][j]);
                        }
                        else if(W[i][j] == -1 && fluxo[i][j] < C[i][j]){
                            vetorDeMarcas[j].verticeAntecessor = i;
                            vetorDeMarcas[j].deltaFluxo = min(vetorDeMarcas[i].deltaFluxo, fluxo[i][j]);
                        }                   
                    }
                }
            }
        }
        int z = n-1;
        do
        {
            if(z == 0){
                for(int i=0; i<n; i++){
                    vetorDeMarcas[i].verticeAntecessor = -1;
                    vetorDeMarcas[i].deltaFluxo = 0;
                    vetorVisitados[i] = 0;
                }
                break;
            }

            int y = vetorDeMarcas[z].verticeAntecessor;

            if(W[y][z] == 1){
                fluxo[y][z] == fluxo[y][z] + vetorDeMarcas[n-1].deltaFluxo;
                fluxo[z][y] == fluxo[y][z] + vetorDeMarcas[n-1].deltaFluxo;
            }
            else{
                fluxo[y][z] == fluxo[y][z] - vetorDeMarcas[n-1].deltaFluxo;
                fluxo[z][y] == fluxo[y][z] - vetorDeMarcas[n-1].deltaFluxo;
            }

            z = y;
        }while (z != 0);
        
    } while(vetorDeMarcas[n-1].verticeAntecessor == -1);

    int fluxoMaximo = 0;
    for (int i=0; i<n; i++){
        if(W[0][i] == 1){
            fluxoMaximo += fluxo[0][i];        
            }
    }
    return fluxoMaximo;
}