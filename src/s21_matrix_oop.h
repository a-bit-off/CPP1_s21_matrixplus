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

  // Helpers func
  void CreateMatrix();
  void BringToZero();
  void ClearMatrix();
  void CopyMatrix(const S21Matrix& other);
  void Minor(S21Matrix& result, int rows, int columns);
  void ManagerSumSub(const S21Matrix& other, bool flag);

 public:
  // Constructors and destructor
  S21Matrix();
  S21Matrix(int rows, int columns);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  // Getters
  int GetRows() { return this->rows_; }
  int GetColumns() { return this->columns_; }
  double** GetMatrix() { return this->matrix_; }

  // Setters
  void SetRows(int rows) { this->rows_ = rows; }
  void SetColumns(int columns) { this->columns_ = columns; }
  void SetElement(int i, int j, double value) { this->matrix_[i][j] = value; }

  // main functions
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  double Determinant();
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

  // overload operators
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