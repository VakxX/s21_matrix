#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (matrix_not_null(A) || negative_size(A->rows, A->columns) ||
      matrix_not_null(B) || negative_size(B->rows, B->columns) ||
      matrix_not_null(result)) {
    res = INCORRECT_MATRIX;
  } else if (qual_size(A, B))
    res = ERROR_CALC;

  else {
    s21_create_matrix(A->rows, A->columns, result);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return res;
}