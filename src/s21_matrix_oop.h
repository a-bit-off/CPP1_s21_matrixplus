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
  // Constructors and destructor
  S21Matrix();
  S21Matrix(int rows, int columns);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  // Secondary functions
  void CreateMatrix();
  void BringToZero();
  void ClearMatrix();
  void CopyMatrix(const S21Matrix& other);
  void Minor(S21Matrix& result, int rows, int columns);
  void ManagerSumSub(const S21Matrix& other, bool flag);

  // Getters and setters
  int GetRows();
  int GetColumns();
  double** GetMatrix();
  void SetRows(int rows);
  void SetColumns(int columns);

  // Main functions
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  double Determinant();
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

  // Overload operators
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*=(const S21Matrix& other);
  S21Matrix operator*=(const double num);
  S21Matrix& operator=(const S21Matrix& other);
  bool operator==(const S21Matrix& other);
  double& operator()(int i, int j);
};

#endif  // SRC_S21_MATRIX_OOP_H