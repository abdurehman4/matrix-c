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

#endif // !MATRIX_H
