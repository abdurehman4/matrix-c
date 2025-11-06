#ifndef MATRIX_H
#define MATRIX_H

struct Matrix {
  int n; // Rows
  int m; // Columns
  int **rows;
};

typedef struct Matrix matrix_t;

void createMatrix(matrix_t *matrix);
int getMatrix(matrix_t *matrix);
void pMatrix(matrix_t *matrix);
void freeMatrix(matrix_t *matrix);
int addMatrices(matrix_t A, matrix_t B, matrix_t *C);

#endif // !MATRIX_H
