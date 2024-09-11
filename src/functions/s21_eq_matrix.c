#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (matrix_not_null(A) || negative_size(A->rows, A->columns) ||
      negative_size(B->rows, B->columns) || matrix_not_null(B) ||
      qual_size(A, B)) {
    res = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) {
          res = FAILURE;
          break;
        }
      }
    }
  }
  return res;
}