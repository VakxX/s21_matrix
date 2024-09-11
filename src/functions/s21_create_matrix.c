#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = OK;
  if (matrix_not_null(result) || negative_size(rows, columns)) {
    res = INCORRECT_MATRIX;
  } else {
    result->matrix = (double **)malloc(sizeof(double *) * rows);
    if (result->matrix == NULL) {
      return ERROR_CALC;
    }
    result->rows = rows;
    result->columns = columns;
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)malloc(sizeof(double) * columns);
    }
  }
  return res;
}