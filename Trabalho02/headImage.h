int **createMatrix(int *mainRows, int *mainCols);
int **createRegister();
void printMatrix(int **matrix, int rows, int columns);
int countComponents(int **matrix, int **registers, int rows, int columns);
int breathSearch(int **matrix, int **registers, int row, int col);