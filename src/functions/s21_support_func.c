#include "../s21_matrix.h"

int matrix_not_null(matrix_t *A) {
  if (A == NULL)
    return TRUE;
  else
    return FALSE;
}

int negative_size(int rows, int columns) {
  if (rows <= 0 || columns <= 0)
    return TRUE;
  else
    return FALSE;
}

int qual_size(matrix_t *A, matrix_t *B) {
  if (A->rows != B->rows || A->columns != B->columns)
    return TRUE;
  else
    return FALSE;
}

void copy_matrix(matrix_t *A, matrix_t *B) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      B->matrix[i][j] = A->matrix[i][j];
    }
  }
}

void swap_rows(matrix_t *A, int row1, int row2) {
  for (int i = 0; i < A->rows; i++) {
    double temp = A->matrix[row1][i];
    A->matrix[row1][i] = A->matrix[row2][i];
    A->matrix[row2][i] = temp;
  }
}

void sub_row(matrix_t *A, int row1, int row2, double multiplier) {
  for (int i = 0; i < A->rows; i++) {
    A->matrix[row2][i] -= multiplier * A->matrix[row1][i];
  }
}

void minor_record(matrix_t *min_matrix, matrix_t *A, int minor_row,
                  int minor_col) {
  for (int i = 0, min_matrix_row = 0; i < A->rows; i++) {
    for (int j = 0, min_matrix_col = 0; j < A->columns; j++) {
      if (minor_row != i && minor_col != j) {
        min_matrix->matrix[min_matrix_row][min_matrix_col] = A->matrix[i][j];
        min_matrix_col++;

        if (min_matrix_col == min_matrix->columns) {
          min_matrix_row++;
          min_matrix_col = 0;
        }
      }
    }
  }
}