#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (matrix_not_null(A) || matrix_not_null(B) ||
      negative_size(A->rows, A->columns) ||
      negative_size(B->rows, B->columns) || matrix_not_null(result)) {
    res = INCORRECT_MATRIX;
  } else if ((A->rows != B->columns) || (A->columns != B->rows))
    res = ERROR_CALC;

  else {
    s21_create_matrix(A->rows, B->columns, result);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < B->rows; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          ;
        }
      }
    }
  }
  return res;
}