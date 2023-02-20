#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(Test, Constructor_1) {
  S21Matrix A;
  EXPECT_EQ(0, A.GetRows());
  EXPECT_EQ(0, A.GetColumns());
}

TEST(Test, Constructor_2) {
  S21Matrix A(4, 4);
  EXPECT_EQ(4, A.GetRows());
  EXPECT_EQ(4, A.GetColumns());
}

TEST(Test, Constructor_3) {
  S21Matrix A(3, 4);
  S21Matrix B(A);
  EXPECT_EQ(3, B.GetRows());
  EXPECT_EQ(4, B.GetColumns());
  EXPECT_EQ(1, A == B);
}

TEST(Test, Constructor_4) {
  S21Matrix A(5, 5);
  S21Matrix B(std::move(A));
  EXPECT_EQ(5, B.GetRows());
  EXPECT_EQ(5, B.GetColumns());
  EXPECT_EQ(0, A.GetRows());
  EXPECT_EQ(0, A.GetColumns());
}

TEST(Test, Throw_SetRows_1) {
  S21Matrix A;
  EXPECT_ANY_THROW(A.SetRows(-1));
}

TEST(Test, Throw_SetColumns_1) {
  S21Matrix A;
  EXPECT_ANY_THROW(A.SetColumns(-1));
}

TEST(Test, Throw_EqMatrix_1) {
  S21Matrix A;
  S21Matrix B;
  EXPECT_ANY_THROW(A.EqMatrix(B));
}

TEST(Test, Throw_EqMatrix_2) {
  S21Matrix A;
  S21Matrix B(1, 1);

  EXPECT_ANY_THROW(A.EqMatrix(B));
}

TEST(Test, Throw_EqMatrix_3) {
  S21Matrix A(1, 4);
  S21Matrix B(3, 4);
  EXPECT_ANY_THROW(A.EqMatrix(B));
}

TEST(Test, Throw_SumMatrix_1) {
  S21Matrix A;
  S21Matrix B;
  EXPECT_ANY_THROW(A.SumMatrix(B));
}

TEST(Test, Throw_SumMatrix_2) {
  S21Matrix A;
  S21Matrix B(1, 1);
  EXPECT_ANY_THROW(A.SumMatrix(B));
}

TEST(Test, Throw_SumMatrix_3) {
  S21Matrix A(1, 4);
  S21Matrix B(3, 4);
  EXPECT_ANY_THROW(A.SumMatrix(B));
}

TEST(Test, Throw_SubMatrix_1) {
  S21Matrix A;
  S21Matrix B;
  EXPECT_ANY_THROW(A.SubMatrix(B));
}

TEST(Test, Throw_SubMatrix_2) {
  S21Matrix A;
  S21Matrix B(1, 1);
  EXPECT_ANY_THROW(A.SubMatrix(B));
}

TEST(Test, Throw_SubMatrix_3) {
  S21Matrix A(1, 4);
  S21Matrix B(3, 4);
  EXPECT_ANY_THROW(A.SubMatrix(B));
}

TEST(Test, Throw_MulMatrix_1) {
  S21Matrix A;
  S21Matrix B;
  EXPECT_ANY_THROW(A.MulMatrix(B));
}

TEST(Test, Throw_MulMatrix_2) {
  S21Matrix A;
  S21Matrix B(1, 1);
  EXPECT_ANY_THROW(A.MulMatrix(B));
}

TEST(Test, Throw_MulMatrix_3) {
  S21Matrix A(1, 2);
  S21Matrix B(1, 2);
  EXPECT_ANY_THROW(A.MulMatrix(B));
}

TEST(Test, Throw_MulNumber_1) {
  S21Matrix A;
  const double num = 5;
  EXPECT_ANY_THROW(A.MulNumber(num));
}

TEST(Test, Throw_Determinant_1) {
  S21Matrix A;
  EXPECT_ANY_THROW(A.Determinant());
}

TEST(Test, Throw_Determinant_2) {
  S21Matrix A(3, 4);
  EXPECT_ANY_THROW(A.Determinant());
}

TEST(Test, Throw_Transpose_1) {
  S21Matrix A;
  EXPECT_ANY_THROW(A.Transpose());
}

TEST(Test, Throw_CalcComplements_1) {
  S21Matrix A;
  EXPECT_ANY_THROW(A.CalcComplements());
}

TEST(Test, Throw_CalcComplements_2) {
  S21Matrix A(2, 3);
  EXPECT_ANY_THROW(A.CalcComplements());
}

TEST(Test, Throw_InverseMatrix_1) {
  S21Matrix A;
  EXPECT_ANY_THROW(A.InverseMatrix());
}

TEST(Test, Throw_InverseMatrix_2) {
  S21Matrix A(3, 4);
  EXPECT_ANY_THROW(A.InverseMatrix());
}

TEST(Test, Throw_operator_index) {
  S21Matrix A(3, 2);
  EXPECT_ANY_THROW(A.operator()(-1, 0));
  EXPECT_ANY_THROW(A.operator()(5, 0));
}

TEST(Test, GetRows_1) {
  S21Matrix A(3, 3);
  EXPECT_EQ(3, A.GetRows());
}

TEST(Test, GetRows_2) {
  S21Matrix A(5, 2);
  EXPECT_EQ(5, A.GetRows());
}

TEST(Test, GetColumns_1) {
  S21Matrix A(3, 3);
  EXPECT_EQ(3, A.GetColumns());
}

TEST(Test, GetColumns_2) {
  S21Matrix A(3, 3);
  EXPECT_EQ(3, A.GetColumns());
}

TEST(Test, SetRows_1) {
  S21Matrix A(3, 3);
  A.SetRows(4);
  EXPECT_EQ(4, A.GetRows());
}

TEST(Test, SetRows_2) {
  S21Matrix A(3, 3);
  EXPECT_ANY_THROW(A.SetRows(-1));
}

TEST(Test, SetColumns_1) {
  S21Matrix A(3, 3);
  A.SetColumns(7);
  EXPECT_EQ(7, A.GetColumns());
}

TEST(Test, SetColumns_2) {
  S21Matrix A(3, 3);
  EXPECT_ANY_THROW(A.SetColumns(-1));
}

TEST(Test, Operator_equal_1) {
  S21Matrix A(1, 1);
  S21Matrix B(1, 1);
  A(0, 0) = 1;
  B(0, 0) = 2;
  EXPECT_EQ(false, A == B);
}

TEST(Test, Operator_equal_2) {
  S21Matrix A(1, 1);
  S21Matrix B(1, 1);
  A(0, 0) = 2;
  B(0, 0) = 2;
  EXPECT_EQ(true, A == B);
}

TEST(Test, Operator_plus_1) {
  S21Matrix A(3, 4);
  S21Matrix B(3, 4);
  B(0, 0) = 2;
  B(0, 1) = 4;
  B(0, 2) = 6;
  B(0, 3) = 2;
  B(1, 0) = 10;
  B(1, 1) = 12;
  B(1, 2) = 95;
  B(1, 3) = 94;
  B(2, 0) = 18;
  B(2, 1) = 94;
  B(2, 2) = 22;
  B(2, 3) = 98;
  A = B + B;
  B += B;
  EXPECT_EQ(true, A == B);
}

TEST(Test, Operator_plus_2) {
  S21Matrix A(3, 4);
  S21Matrix B(3, 4);
  B(0, 0) = 2;
  B(0, 1) = 4;
  B(0, 2) = 6;
  B(0, 3) = 2;
  B(1, 0) = 10;
  B(1, 1) = 12;
  B(1, 2) = 95;
  B(1, 3) = 94;
  B(2, 0) = 18;
  B(2, 1) = 94;
  B(2, 2) = 22;
  B(2, 3) = 98;
  A = B;
  A += B;
  EXPECT_EQ(1, A == (B + B));
}

TEST(Test, Operator_minus_1) {
  S21Matrix A(3, 4);
  S21Matrix B(3, 4);
  B(0, 0) = 2;
  B(0, 1) = 4;
  B(0, 2) = 6;
  B(0, 3) = 2;
  B(1, 0) = 10;
  B(1, 1) = 12;
  B(1, 2) = 95;
  B(1, 3) = 94;
  B(2, 0) = 18;
  B(2, 1) = 94;
  B(2, 2) = 22;
  B(2, 3) = 98;
  A = B - B;
  EXPECT_EQ(true, A == (B - B));
}

TEST(Test, Operator_minus_2) {
  S21Matrix A(3, 4);
  S21Matrix B(3, 4);
  B(0, 0) = 2;
  B(0, 1) = 4;
  B(0, 2) = 6;
  B(0, 3) = 2;
  B(1, 0) = 10;
  B(1, 1) = 12;
  B(1, 2) = 95;
  B(1, 3) = 94;
  B(2, 0) = 18;
  B(2, 1) = 94;
  B(2, 2) = 22;
  B(2, 3) = 98;
  A = B;
  A -= B;
  EXPECT_EQ(1, A == (B - B));
}

TEST(Test, Operator_mul_num_1) {
  S21Matrix A(3, 4);
  S21Matrix B(3, 4);
  B(0, 0) = 2;
  B(0, 1) = 4;
  B(0, 2) = 6;
  B(0, 3) = 2;
  B(1, 0) = 10;
  B(1, 1) = 12;
  B(1, 2) = 95;
  B(1, 3) = 94;
  B(2, 0) = 18;
  B(2, 1) = 94;
  B(2, 2) = 22;
  B(2, 3) = 98;
  A = B * 5;
  EXPECT_EQ(1, A == (B * 5));
}

TEST(Test, Operator_mul_num_2) {
  S21Matrix A(3, 4);
  S21Matrix B(3, 4);
  B(0, 0) = 2;
  B(0, 1) = 4;
  B(0, 2) = 6;
  B(0, 3) = 2;
  B(1, 0) = 10;
  B(1, 1) = 12;
  B(1, 2) = 95;
  B(1, 3) = 94;
  B(2, 0) = 18;
  B(2, 1) = 94;
  B(2, 2) = 22;
  B(2, 3) = 98;
  A = B;
  A *= 5;
  EXPECT_EQ(1, A == B * 5);
}

TEST(Test, Operator_mul_num_3) {
  S21Matrix A(3, 3);
  A(0, 0) = 2;
  A(0, 1) = 4;
  A(0, 2) = 6;
  A(1, 0) = 2;
  A(1, 1) = 10;
  A(1, 2) = 12;
  A(2, 0) = 95;
  A(2, 1) = 94;
  A(2, 2) = 18;

  S21Matrix B(3, 3);
  B(0, 0) = 2;
  B(0, 1) = 4;
  B(0, 2) = 6;
  B(1, 0) = 2;
  B(1, 1) = 10;
  B(1, 2) = 12;
  B(2, 0) = 95;
  B(2, 1) = 94;
  B(2, 2) = 18;

  S21Matrix res(3, 3);
  res(0, 0) = 582;
  res(0, 1) = 612;
  res(0, 2) = 168;
  res(1, 0) = 1164;
  res(1, 1) = 1236;
  res(1, 2) = 348;
  res(2, 0) = 2088;
  res(2, 1) = 3012;
  res(2, 2) = 2022;

  EXPECT_EQ(1, (A * B) == res);
}

TEST(Test, Operator_mul_num_4) {
  S21Matrix A(3, 3);
  A(0, 0) = 2;
  A(0, 1) = 4;
  A(0, 2) = 6;
  A(1, 0) = 2;
  A(1, 1) = 10;
  A(1, 2) = 12;
  A(2, 0) = 95;
  A(2, 1) = 94;
  A(2, 2) = 18;

  S21Matrix B(3, 3);
  B(0, 0) = 2;
  B(0, 1) = 4;
  B(0, 2) = 6;
  B(1, 0) = 2;
  B(1, 1) = 10;
  B(1, 2) = 12;
  B(2, 0) = 95;
  B(2, 1) = 94;
  B(2, 2) = 18;

  S21Matrix res(3, 3);
  res(0, 0) = 582;
  res(0, 1) = 612;
  res(0, 2) = 168;
  res(1, 0) = 1164;
  res(1, 1) = 1236;
  res(1, 2) = 348;
  res(2, 0) = 2088;
  res(2, 1) = 3012;
  res(2, 2) = 2022;
  A *= B;
  EXPECT_EQ(1, A == res);
}

TEST(Test, Operator_index_1) {
  S21Matrix A(3, 3);
  A.operator()(0, 0) = 5;
  EXPECT_EQ(5, A.operator()(0, 0));
}

TEST(Test, Determinant_1) {
  S21Matrix A(3, 3);
  A.operator()(0, 0) = 8;
  A.operator()(0, 1) = 2;
  A.operator()(0, 2) = 4;
  A.operator()(1, 0) = 4;
  A.operator()(1, 1) = 6;
  A.operator()(1, 2) = 6;
  A.operator()(2, 0) = 4;
  A.operator()(2, 1) = 8;
  A.operator()(2, 2) = 8;
  EXPECT_EQ(16, A.Determinant());
}

TEST(Test, Determinant_2) {
  S21Matrix A(1, 1);
  A.operator()(0, 0) = 5;
  EXPECT_EQ(5, A.Determinant());
}

TEST(Test, Transpose_1) {
  S21Matrix A(3, 4);
  A.operator()(0, 0) = 1;
  A.operator()(0, 1) = 2;
  A.operator()(0, 2) = 3;
  A.operator()(0, 3) = 4;
  A.operator()(1, 0) = 5;
  A.operator()(1, 1) = 6;
  A.operator()(1, 2) = 7;
  A.operator()(1, 3) = 8;
  A.operator()(2, 0) = 9;
  A.operator()(2, 1) = 10;
  A.operator()(2, 2) = 11;
  A.operator()(2, 3) = 12;
  S21Matrix B;
  B = A.Transpose();
  EXPECT_EQ(4, B.GetRows());
  EXPECT_EQ(3, B.GetColumns());
}

TEST(Test, InverseMatrix_1) {
  S21Matrix result(3, 3);
  result(0, 0) = 0;
  result(0, 1) = 1;
  result(0, 2) = -0.75;
  result(1, 0) = -0.5;
  result(1, 1) = 3;
  result(1, 2) = -2;
  result(2, 0) = 0.5;
  result(2, 1) = -3.5;
  result(2, 2) = 2.5;

  S21Matrix result_inverse(3, 3);

  S21Matrix R(3, 3);
  R.operator()(0, 0) = 8;
  R.operator()(0, 1) = 2;
  R.operator()(0, 2) = 4;
  R.operator()(1, 0) = 4;
  R.operator()(1, 1) = 6;
  R.operator()(1, 2) = 6;
  R.operator()(2, 0) = 4;
  R.operator()(2, 1) = 8;
  R.operator()(2, 2) = 8;

  result_inverse = R.InverseMatrix();
  EXPECT_EQ(1, result == result_inverse);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}