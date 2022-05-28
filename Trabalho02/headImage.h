int **createMatrix(int *mainRows, int *mainCols);
int **createRegister();
void printMatrix(int **matrix, int rows, int columns);
int countComponents(int **matrix, int **registers, int rows, int columns);
void deepSearch(int **matrix, int **registers, int row, int col);
int R, C;