#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

void createMatrix(matrix_t *matrix);
int getMatrix(matrix_t *matrix);
void pMatrix(matrix_t *matrix);
void freeMatrix(matrix_t *matrix);
int addMatrices(matrix_t A, matrix_t B, matrix_t *C);
int multiplyMatrices(matrix_t A, matrix_t B, matrix_t *C);

int main() {
  matrix_t A;
  matrix_t B;
  matrix_t C;

  // Printing the options
  while (1) {
    int option = 1;
    printf("Select an Option:\n");
    puts("1] Setup Matrix A.");
    puts("2] Setup Matrix B.");
    puts("3] Print Matrix A");
    puts("4] Print Matrix B");
    puts("5] Print Resultant Matrix");
    puts("6] Add Matrices.");
    puts("7] Multiply A & B");
    puts("8] Exit");
    printf("-> ");
    scanf("%d", &option);
    printf("Your option is : %d\n", option);

    switch (option) {
    case 1:
      createMatrix(&A);
      break;
    case 2:
      createMatrix(&B);
      break;
    case 3:
      pMatrix(&A);
      break;
    case 4:
      pMatrix(&B);
      break;
    case 5:
      pMatrix(&C);
      break;
    case 6:
      addMatrices(A, B, &C);
      break;
    case 7:
      multiplyMatrices(A, B, &C);
      break;
    case 8:
      freeMatrix(&A);
      freeMatrix(&B);
      return 0;
    default:
      puts("Wrong Option! Try Again!!");
      break;
    }
  }

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
  getMatrix(matrix);
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
  if (matrix->n == 0 || matrix->m == 0) {
    puts("--------------");
    puts("Empty Matrix!!");
    puts("--------------");
  } else {
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
}

void freeMatrix(matrix_t *matrix) {
  for (int i = 0; i < matrix->n; i++) {
    free(matrix->rows[i]);
  }
  free(matrix->rows);
}

int addMatrices(matrix_t A, matrix_t B, matrix_t *C) {
  // Check whether addition is possible
  if (A.m == B.m && A.n == B.n) {
    C->n = A.n;
    C->m = A.m;
    if (C->rows != NULL)
      freeMatrix(C);

    C->rows = (int **)malloc(sizeof(int *) * C->n);
    if (C->rows == NULL) {
      perror("Error allocating the array of rows!\n");
      return -1;
    }
    for (int i = 0; i < C->n; i++) {
      C->rows[i] = (int *)malloc(sizeof(int) * C->m);
      if (C->rows[i] == NULL) {
        perror("Error allocating the row array!\n");
        return -1;
      }
      for (int j = 0; j < C->m; j++) {
        C->rows[i][j] = A.rows[i][j] + B.rows[i][j];
      }
    }
  } else {
    puts("--------------------------");
    puts("Addition is not possible!!");
    puts("--------------------------");
    return -1;
  }
  return 0;
}

int multiplyMatrices(matrix_t A, matrix_t B, matrix_t *C) {
  if (A.m == B.n && A.n != 0 && A.m != 0 && B.n != 0 && B.m != 0) {
    C->n = A.n;
    C->m = B.m;
    if (C->rows != NULL)
      freeMatrix(C);
    C->rows = (int **)malloc(sizeof(int *) * C->n);
    if (C->rows == NULL) {
      perror("Error Allocating the array of rows.");
      return -1;
    } else {
      for (int i = 0; i < C->n; i++) {
        C->rows[i] = (int *)malloc(sizeof(int) * C->m);
        if (C->rows[i] == NULL) {
          perror("Error Allocating the row");
          return -1;
        } else {
          for (int j = 0; j < C->m; j++) {
            int val = 0;
            for (int n = 0; n < A.m; n++) {
              val += A.rows[i][n] * B.rows[n][j];
            }
            C->rows[i][j] = val;
          }
        }
      }
    }
  } else {
    puts("--------------------------------");
    puts("Multiplication is not possible!!");
    puts("--------------------------------");
    return -1;
  }
  return 0;
}
