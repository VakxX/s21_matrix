#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (matrix_not_null(A) || matrix_not_null(result) ||
      negative_size(A->rows, A->columns)) {
    res = INCORRECT_MATRIX;
  } else if (A->columns != A->rows) {
    res = ERROR_CALC;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    matrix_t min_matrix;

    if (A->rows == 1) {
      result->matrix[0][0] = A->matrix[0][0];

    } else {
      s21_create_matrix(A->rows - 1, A->columns - 1, &min_matrix);

      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          minor_record(&min_matrix, A, i, j);
          s21_determinant(&min_matrix, &result->matrix[i][j]);
          if ((i + j) % 2) result->matrix[i][j] *= -1;
        }
      }
      s21_remove_matrix(&min_matrix);
    }
  }

  return res;
}