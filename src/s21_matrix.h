#ifndef S21_MATRIX
#define S21_MATRIX

#include <math.h>
#include <stdlib.h>

#define OK 0
#define INCORRECT_MATRIX 1
#define ERROR_CALC 2

#define SUCCESS 1
#define FAILURE 0

#define TRUE 1
#define FALSE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);

void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// support function

int matrix_not_null(matrix_t *A);
int negative_size(int row, int columns);
int qual_size(matrix_t *A, matrix_t *B);
int inf_or_nan(matrix_t *A);
int size_for_mult(matrix_t *A, matrix_t *B);
void copy_matrix(matrix_t *A, matrix_t *B);
void swap_rows(matrix_t *A, int row1, int row2);
void sub_row(matrix_t *A, int row1, int row2, double multiplier);
void minor_record(matrix_t *min_matrix, matrix_t *A, int minor_row,
                  int minor_col);

#endif  // S21_MATRIX