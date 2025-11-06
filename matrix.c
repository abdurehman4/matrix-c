#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

void createMatrix(matrix_t *matrix);
int getMatrix(matrix_t *matrix);
void pMatrix(matrix_t *matrix);

int main() {
  matrix_t twoBytwo;
  createMatrix(&twoBytwo);
  getMatrix(&twoBytwo);
  pMatrix(&twoBytwo);
  return 0;
}

void createMatrix(matrix_t *matrix) {
  int n, m;
  printf("Number of Rows : ");
  scanf("%d", &n);
  printf("Number of Columns : ");
  scanf("%d", &m);
  matrix->n = n;
  matrix->m = m;
}

int getMatrix(matrix_t *matrix) {
  matrix->rows = (int **)malloc(sizeof(int *) * matrix->n);
  if (matrix->rows == NULL) {
    perror("Error allocating the array of rows!\n");
    return -1;
  }
  for (int i = 0; i < matrix->n; i++) {
    matrix->rows[i] = (int *)malloc(sizeof(int) * matrix->m);
    if (matrix->rows[i] == NULL) {
      perror("Error allocating the row array!\n");
      return -1;
    }
    for (int j = 0; j < matrix->m; j++) {
      int value;
      printf("[%d][%d] : ", i + 1, j + 1);
      scanf("%d", &value);
      matrix->rows[i][j] = value;
    }
  }
  return 0;
}

void pMatrix(matrix_t *matrix) {
  printf("----------%d by %d Matrix-----------\n", matrix->n, matrix->m);
  for (int i = 0; i < matrix->n; i++) {
    for (int j = 0; j < matrix->m; j++) {
      if (j != matrix->m - 1)
        printf("%d\t", matrix->rows[i][j]);
      else
        printf("%d", matrix->rows[i][j]);
    }
    puts("");
  }
}
