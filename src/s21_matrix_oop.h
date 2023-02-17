#ifndef SRC_S21_MATRIX_OOP_H
#define SRC_S21_MATRIX_OOP_H
#include <cmath>
#include <iostream>
#include <stdexcept>

class S21Matrix {
 private:
  int rows_;
  int columns_;
  double** matrix_;

 public:
  S21Matrix();
  S21Matrix(int rows, int columns);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  void Print();  // ------------------------------------------------ delete it
  void CreateMatrix();
  void BringToZero();
  void ClearMatrix();
  void CopyMatrix(const S21Matrix& other);

  int GetRows();
  int GetColumns();
  double **GetMatrix();
  void SetRows(int rows);
  void SetColumns(int columns);
  void SetMatrix(double **matrix);

  bool EqMatrix(const S21Matrix& other);
  void ManagerSumSub(const S21Matrix& other, bool flag);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);

  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // void cut_matrix(S21Matrix& result, int rows_A, int columns_A);

  // S21Matrix& operator=(const S21Matrix& other);
  // bool operator==(const S21Matrix& other);
  // S21Matrix operator+=(const S21Matrix& other);
  // S21Matrix operator-=(const S21Matrix& other);
  // S21Matrix operator*=(const S21Matrix& other);
  // S21Matrix operator*=(const double num);
  // S21Matrix operator+(const S21Matrix& other);
  // S21Matrix operator-(const S21Matrix& other);
  // S21Matrix operator*(const S21Matrix& other);
  // S21Matrix operator*(const double num);
  // double& operator()(int i, int j);
};

#endif  // SRC_S21_MATRIX_OOP_H