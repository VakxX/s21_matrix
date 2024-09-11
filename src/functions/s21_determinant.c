#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int res = OK;
  if (matrix_not_null(A) || negative_size(A->rows, A->columns) ||
      result == NULL) {
    res = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    res = ERROR_CALC;
  } else {
    matrix_t new_matrix;
    s21_create_matrix(A->rows, A->columns, &new_matrix);

    copy_matrix(A, &new_matrix);

    *result = 1;
    for (int i = 0; i < new_matrix.rows; i++) {
      if (new_matrix.matrix[i][i] == 0) {
        int j = i + 1;
        while (j < new_matrix.rows && new_matrix.matrix[j][i] == 0) {
          j++;
        }
        if (j == new_matrix.rows) {
          *result = 0;
          s21_remove_matrix(&new_matrix);
          return OK;
        }
        swap_rows(&new_matrix, i, j);
        *result *= -1;
      }
      *result *= new_matrix.matrix[i][i];
      for (int j = i + 1; j < new_matrix.rows; j++) {
        double multiplier = new_matrix.matrix[j][i] / new_matrix.matrix[i][i];
        sub_row(&new_matrix, i, j, multiplier);
      }
    }
    s21_remove_matrix(&new_matrix);
  }

  return res;
}