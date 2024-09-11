#include <check.h>
#include <errno.h>

#include "../s21_matrix.h"

// create_matrix
START_TEST(test_s21_create_matrix_1) {
  matrix_t A;
  int res = s21_create_matrix(2, 3, &A);
  ck_assert_int_eq(A.rows, 2);
  ck_assert_int_eq(A.columns, 3);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_2) {
  matrix_t A;
  int res = s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(A.rows, 3);
  ck_assert_int_eq(A.columns, 3);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_3) {
  matrix_t A;
  int res = s21_create_matrix(0, 3, &A);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_s21_create_matrix_4) {
  matrix_t A;
  int res = s21_create_matrix(3, -3, &A);
  ck_assert_int_eq(res, 1);
}
END_TEST

// eq_matrix
START_TEST(test_s21_eq_matrix_1) {
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = count;
      count = count + 1.0;
    }
  }
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_2) {
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 1, &A);
  s21_create_matrix(3, 1, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = count;
      count = count + 1.0;
    }
  }
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_3) {
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = count;
      count = count + 1.0;
    }
  }
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  B.matrix[2][2] += 0.0000009;
  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_4) {
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = count + 1.0;
      count = count + 1.0;
    }
  }
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_5) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 1, &A);
  s21_create_matrix(3, 3, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// sum_matrix
START_TEST(test_s21_sum_matrix_1) {
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &C);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = count;
      C.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
      count = count + 1.0;
    }
  }

  int res = s21_sum_matrix(&A, &B, &D);
  int res_eq = s21_eq_matrix(&C, &D);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sum_matrix_2) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(3, 1, &A);
  s21_create_matrix(3, 3, &B);

  int res = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// sub_matrix
START_TEST(test_s21_sub_matrix_1) {
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &C);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = count;
      C.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
      count = count + 1.0;
    }
  }

  int res = s21_sub_matrix(&A, &B, &D);
  int res_eq = s21_eq_matrix(&C, &D);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sub_matrix_2) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(3, 1, &A);
  s21_create_matrix(3, 3, &B);

  int res = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_mult_number_1) {
  double number = 2.0;
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = A.matrix[i][j] * number;
      count = count + 1.0;
    }
  }

  int res = s21_mult_number(&A, number, &C);
  int res_eq = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

// mult_matrix
START_TEST(test_s21_mult_matrix_1) {
  double count = 1.0;
  double count2 = 3.0;
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(3, 1, &B);
  s21_create_matrix(1, 1, &C);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[j][i] = count2;
      count = count + 1.0;
      count2 = count2 - 1.0;
    }
  }

  C.matrix[0][0] = 10.0;

  int res = s21_mult_matrix(&A, &B, &D);
  int res_eq = s21_eq_matrix(&C, &D);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_mult_matrix_2) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(4, 1, &B);
  s21_create_matrix(1, 1, &C);

  int res = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

// transpose
START_TEST(test_s21_transpose_1) {
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[j][i] = count;
      count = count + 1.0;
    }
  }

  int res = s21_transpose(&A, &C);
  int res_eq = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

// calc_complements
START_TEST(test_s21_calc_complements_1) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  int res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(B.matrix[0][0], 0);
  ck_assert_int_eq(B.matrix[0][1], 10);
  ck_assert_int_eq(B.matrix[0][2], -20);
  ck_assert_int_eq(B.matrix[1][0], 4);
  ck_assert_int_eq(B.matrix[1][1], -14);
  ck_assert_int_eq(B.matrix[1][2], 8);
  ck_assert_int_eq(B.matrix[2][0], -8);
  ck_assert_int_eq(B.matrix[2][1], -2);
  ck_assert_int_eq(B.matrix[2][2], 4);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_calc_complements_2) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 3;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 2;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 8;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 2;

  int res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(B.matrix[0][0], -12);
  ck_assert_int_eq(B.matrix[0][1], 20);
  ck_assert_int_eq(B.matrix[0][2], -2);
  ck_assert_int_eq(B.matrix[1][0], 0);
  ck_assert_int_eq(B.matrix[1][1], 0);
  ck_assert_int_eq(B.matrix[1][2], 0);
  ck_assert_int_eq(B.matrix[2][0], 12);
  ck_assert_int_eq(B.matrix[2][1], -20);
  ck_assert_int_eq(B.matrix[2][2], 2);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_calc_complements_3) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 1, &A);

  int res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_calc_complements_4) {
  matrix_t matrix1;
  matrix_t matrix_result;
  int return_value, rows = 1, cols = 1;
  s21_create_matrix(rows, cols, &matrix1);
  return_value = s21_calc_complements(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, 0);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix_result);
}
END_TEST

// determinant
START_TEST(test_s21_determinant_1) {
  matrix_t matrix1;
  double determinant = 0;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;
  matrix1.matrix[1][0] = 4;
  matrix1.matrix[1][1] = 5;
  matrix1.matrix[1][2] = 6;
  matrix1.matrix[2][0] = 7;
  matrix1.matrix[2][1] = 8;
  matrix1.matrix[2][2] = 9;
  return_value = s21_determinant(&matrix1, &determinant);
  ck_assert_int_eq(return_value, 0);
  ck_assert_double_eq(determinant, 0);
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(test_s21_determinant_2) {
  matrix_t matrix1;
  double determinant = 0;
  int return_value, rows = 3, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  return_value = s21_determinant(&matrix1, &determinant);
  ck_assert_int_eq(return_value, 2);
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(test_s21_determinant_3) {
  matrix_t matrix1;
  double determinant = 0;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  matrix1.matrix[0][0] = 0;
  matrix1.matrix[0][1] = 0;
  matrix1.matrix[0][2] = 0;
  matrix1.matrix[1][0] = 0;
  matrix1.matrix[1][1] = 0;
  matrix1.matrix[1][2] = 0;
  matrix1.matrix[2][0] = 0;
  matrix1.matrix[2][1] = 0;
  matrix1.matrix[2][2] = 0;
  return_value = s21_determinant(&matrix1, &determinant);
  s21_remove_matrix(&matrix1);
  ck_assert_int_eq(return_value, 0);
  ck_assert_double_eq(determinant, 0);
}
END_TEST

START_TEST(test_s21_determinant_4) {
  matrix_t matrix1;
  double determinant = 0;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  matrix1.matrix[0][0] = 0;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 4;
  matrix1.matrix[1][0] = 1;
  matrix1.matrix[1][1] = 3;
  matrix1.matrix[1][2] = 3;
  matrix1.matrix[2][0] = 2;
  matrix1.matrix[2][1] = 3;
  matrix1.matrix[2][2] = 1;
  return_value = s21_determinant(&matrix1, &determinant);
  s21_remove_matrix(&matrix1);
  ck_assert_int_eq(return_value, 0);
  ck_assert_double_eq(determinant, -2);
}
END_TEST

START_TEST(test_s21_determinant_5) {
  matrix_t matrix1;
  double determinant = 0;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  s21_remove_matrix(&matrix1);

  return_value = s21_determinant(&matrix1, &determinant);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

// inverse_matrix
START_TEST(test_s21_inverse_matrix_1) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;

  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;

  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(B.matrix[0][0], 1);
  ck_assert_int_eq(B.matrix[0][1], -1);
  ck_assert_int_eq(B.matrix[0][2], 1);
  ck_assert_int_eq(B.matrix[1][0], -38);
  ck_assert_int_eq(B.matrix[1][1], 41);
  ck_assert_int_eq(B.matrix[1][2], -34);
  ck_assert_int_eq(B.matrix[2][0], 27);
  ck_assert_int_eq(B.matrix[2][1], -29);
  ck_assert_int_eq(B.matrix[2][2], 24);
  s21_remove_matrix(&A);
  // s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_inverse_matrix_2) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 2;

  A.matrix[1][0] = 2;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 8;

  A.matrix[2][0] = 3;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 2;

  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_3) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 2, &A);

  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

int main() {
  Suite *s1 = suite_create("s21_matrix: ");
  TCase *tc1_1 = tcase_create("s21_matrix: ");
  SRunner *sr = srunner_create(s1);
  int result;
  suite_add_tcase(s1, tc1_1);

  // create_matrix
  tcase_add_test(tc1_1, test_s21_create_matrix_1);
  tcase_add_test(tc1_1, test_s21_create_matrix_2);
  tcase_add_test(tc1_1, test_s21_create_matrix_3);
  tcase_add_test(tc1_1, test_s21_create_matrix_4);

  // eq_matrix
  tcase_add_test(tc1_1, test_s21_eq_matrix_1);
  tcase_add_test(tc1_1, test_s21_eq_matrix_2);
  tcase_add_test(tc1_1, test_s21_eq_matrix_3);
  tcase_add_test(tc1_1, test_s21_eq_matrix_4);
  tcase_add_test(tc1_1, test_s21_eq_matrix_5);

  // sum_matrix
  tcase_add_test(tc1_1, test_s21_sum_matrix_1);
  tcase_add_test(tc1_1, test_s21_sum_matrix_2);

  // sub_matrix
  tcase_add_test(tc1_1, test_s21_sub_matrix_1);
  tcase_add_test(tc1_1, test_s21_sub_matrix_2);

  // mult_number
  tcase_add_test(tc1_1, test_s21_mult_number_1);

  // mult_matrix
  tcase_add_test(tc1_1, test_s21_mult_matrix_1);
  tcase_add_test(tc1_1, test_s21_mult_matrix_2);

  // transpose
  tcase_add_test(tc1_1, test_s21_transpose_1);

  // calc_complements
  tcase_add_test(tc1_1, test_s21_calc_complements_1);
  tcase_add_test(tc1_1, test_s21_calc_complements_2);
  tcase_add_test(tc1_1, test_s21_calc_complements_3);
  tcase_add_test(tc1_1, test_s21_calc_complements_4);

  // determinant
  tcase_add_test(tc1_1, test_s21_determinant_1);
  tcase_add_test(tc1_1, test_s21_determinant_2);
  tcase_add_test(tc1_1, test_s21_determinant_3);
  tcase_add_test(tc1_1, test_s21_determinant_4);
  tcase_add_test(tc1_1, test_s21_determinant_5);

  // inverse_matrix
  tcase_add_test(tc1_1, test_s21_inverse_matrix_1);
  tcase_add_test(tc1_1, test_s21_inverse_matrix_2);
  tcase_add_test(tc1_1, test_s21_inverse_matrix_3);

  srunner_run_all(sr, CK_ENV);
  result = srunner_ntests_failed(sr);
  srunner_free(sr);
  return result == 0 ? 0 : 1;
}