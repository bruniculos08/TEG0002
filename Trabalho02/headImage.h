typedef struct Node node;
struct Node {
    int row, column; // Para guardar as coordenadas já visitadas (usar um vetor)
}; // Na verdade da pra criar uma outra matriz pra ficar vendo o que já foi lido.

int **createMatrix(); // Para ler o arquivo

int func(int **matrix); // gera matriz 0, chama função componentes e retorna numero de componentes

int components(int **matrix, int**marcados, int node.row, int node.column, int cont); // passa por todos os valores, chama funcao search e retorna o numero de componentens conexos

void search(int **matrix, int **marcados, int node.row, int node.column); // Verifica vizinhos e marca recursivamente os componentes conexos

int *neighbours(int node.row, int node.column); // retorna os 4 vertices vizinhos