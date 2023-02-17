#include "s21_matrix_oop.h"
using namespace std;

// конструкотры
S21Matrix::S21Matrix() { this->BringToZero(); }

S21Matrix::S21Matrix(int rows, int columns) {
  if (rows < 1 || columns < 1) {
    throw("Rows or Columns less than 1 !!!!");
  }
  this->rows_ = rows;
  this->columns_ = columns;
  this->CreateMatrix();
}

S21Matrix::S21Matrix(const S21Matrix& other) { this->CopyMatrix(other); }

S21Matrix::S21Matrix(S21Matrix&& other) {
  this->BringToZero();
  this->CopyMatrix(other);
  other.ClearMatrix();
}

// деструктор
S21Matrix::~S21Matrix() { this->ClearMatrix(); }

// helpers
void S21Matrix::CreateMatrix() {
  this->matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) {
    this->matrix_[i] = new double[columns_]();
  }
}

void S21Matrix::BringToZero() {
  this->rows_ = 0;
  this->columns_ = 0;
  this->matrix_ = nullptr;
}

void S21Matrix::Print() {
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->columns_; j++) {
      cout << this->matrix_[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void S21Matrix::CopyMatrix(const S21Matrix& other) {
  this->rows_ = other.rows_;
  this->columns_ = other.columns_;
  this->CreateMatrix();
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->columns_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::ClearMatrix() {
  if (this->matrix_ != nullptr) {
    for (int i = 0; i < this->rows_; i++) {
      delete[] this->matrix_[i];
    }
    delete[] this->matrix_;
    this->matrix_ = nullptr;
    this->rows_ = 0;
    this->columns_ = 0;
  }
}

// Getters
int S21Matrix::GetRows() { return this->rows_; }
int S21Matrix::GetColumns() { return this->columns_; }

// Setters
void S21Matrix::SetRows(int rows) { this->rows_ = rows; }
void S21Matrix::SetColumns(int columns) { this->columns_ = columns; }

// основные функции
bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool result = true;
  if (this->matrix_ == nullptr || other.matrix_ == nullptr) {
    result = false;
    throw("Matrix is not empty !!!!");
  }
  if (this->rows_ == other.rows_ && this->columns_ == other.columns_) {
    for (int i = 0; i < this->rows_ && result; i++) {
      for (int j = 0; j < this->columns_ && result; j++) {
        if (fabs(this->matrix_[i][j] - other.matrix_[i][j]) > 0.0000001) {
          result = false;
        }
      }
    }
  }
  other.Get return result;
}

int main() {
  // create test +
  // конструктор S21Matrix(); +
  // Set
  // S21Matrix m1;
  // m1.SetRows(4);
  // m1.SetColumns(4);
  // m1.CreateMatrix();
  // m1.Print();

  // конструктор S21Matrix(int rows, int columns);
  // S21Matrix m2(5, 5);
  // m2.Print();

  // деструктор + get
  // S21Matrix m3(6, 6);
  // m3.Print();
  // m3.~S21Matrix();
  // cout << "m3 = " << m3.GetRows() << " " << m3.GetColumns() << endl;

  S21Matrierfex m1(4, 4);
  S21Matrix m2;
  cout << m1.EqMatrix(m2) <<
}
