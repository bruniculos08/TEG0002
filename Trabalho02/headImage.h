int **createMatrix(int *mainRows, int *mainCols);
int **createRegister();
void printMatrix(int **matrix);
int countComponents(int **matrix, int **registers);
void deepSearch(int **matrix, int **registers, int row, int col);
int R, C;