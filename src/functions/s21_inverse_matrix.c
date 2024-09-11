#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = OK;
  double determinant = 0.;
  s21_determinant(A, &determinant);
  if (matrix_not_null(A) || negative_size(A->rows, A->columns) ||
      matrix_not_null(result) || A->matrix == NULL) {
    res = INCORRECT_MATRIX;
  } else if (A->rows != A->columns || determinant == 0) {
    res = ERROR_CALC;
  } else {
    matrix_t complement, transpose;

    s21_calc_complements(A, &complement);
    s21_transpose(&complement, &transpose);

    determinant = 1 / determinant;

    s21_mult_number(&transpose, determinant, result);

    s21_remove_matrix(&complement);
    s21_remove_matrix(&transpose);
  }
  return res;
}