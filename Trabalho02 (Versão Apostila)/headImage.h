typedef struct Componente componente;
struct Componente {
    int baricentroX, baricentroY, numeroDePixels;
};
componente *lista;
int **createMatrix(int *mainRows, int *mainCols);
int **createRegister();
void printMatrix(int **matrix);
void printComponents();
int countComponents(int **matrix, int **ordena);
void deepSearch(int **matrix, int **registers, int row, int col);
int R, C, visitados, count;