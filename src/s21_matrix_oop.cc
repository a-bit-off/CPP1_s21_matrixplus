#include "s21_matrix_oop.h"
using namespace std;

// Constructors and destructor
S21Matrix::S21Matrix() { this->BringToZero(); }

S21Matrix::S21Matrix(int rows, int columns) {
  if (rows < 1 || columns < 1) {
    throw("Rows or Columns less than 1 !!!");
  }
  this->rows_ = rows;
  this->columns_ = columns;
  this->CreateMatrix();
}

S21Matrix::S21Matrix(const S21Matrix &other) { this->CopyMatrix(other); }

S21Matrix::S21Matrix(S21Matrix &&other) {
  this->CopyMatrix(other);
  other.ClearMatrix();
}

S21Matrix::~S21Matrix() { this->ClearMatrix(); }

// Secondary functions
void S21Matrix::CreateMatrix() {
  this->matrix_ = new double *[rows_]();
  for (int i = 0; i < rows_; i++) {
    this->matrix_[i] = new double[columns_]();
  }
}

void S21Matrix::BringToZero() {
  this->rows_ = 0;
  this->columns_ = 0;
  this->matrix_ = nullptr;
}

void S21Matrix::CopyMatrix(const S21Matrix &other) {
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
  }
  this->rows_ = 0;
  this->columns_ = 0;
}

void S21Matrix::Minor(S21Matrix &result, int rows, int columns) {
  for (int i = 0, a = 0; i < this->rows_; i++) {
    if (columns != i) {
      for (int j = 0, b = 0; j < this->rows_; j++) {
        if (rows != j) {
          result.matrix_[a][b] = this->matrix_[i][j];
          b++;
        }
      }
      a++;
    }
  }
}

// Getters and setters
int S21Matrix::GetRows() { return this->rows_; }

int S21Matrix::GetColumns() { return this->columns_; }

double **S21Matrix::GetMatrix() { return this->matrix_; }

void S21Matrix::SetRows(int rows) {
  if (rows < 1) {
    throw("Rows is less 1 !!!");
  }
  S21Matrix tmp(rows, this->columns_);
  int less_rows = rows;
  if (rows > this->rows_) {
    less_rows = this->rows_;
  }
  for (int i = 0; i < less_rows; i++) {
    for (int j = 0; j < this->columns_; j++) {
      tmp.matrix_[i][j] = this->matrix_[i][j];
    }
  }
  *this = tmp;
}

void S21Matrix::SetColumns(int columns) {
  if (columns < 1) {
    throw("Columns is less 1 !!!");
  }
  S21Matrix tmp(this->rows_, columns);
  int less_columns = columns;
  if (columns > this->columns_) {
    less_columns = this->columns_;
  }
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < less_columns; j++) {
      tmp.matrix_[i][j] = this->matrix_[i][j];
    }
  }
  *this = tmp;
}

// Main functions
bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool result = true;
  if (this->matrix_ == nullptr || other.matrix_ == nullptr) {
    throw("Matrix is not empty !!!");
  } else if ((this->rows_ < 1 || this->columns_ < 1) ||
             (other.rows_ < 1 || other.columns_ < 1)) {
    throw("Matrix size is not correct !!!");
  } else if (this->rows_ != other.rows_ || this->columns_ != other.columns_) {
    throw("Matrix size is not correct !!!");
  }
  for (int i = 0; i < this->rows_ && result; i++) {
    for (int j = 0; j < this->columns_ && result; j++) {
      if (fabs(this->matrix_[i][j] - other.matrix_[i][j]) > 1e-7) {
        result = false;
      }
    }
  }
  return result;
}

void S21Matrix::ManagerSumSub(const S21Matrix &other, bool flag) {
  if (this->matrix_ == nullptr || other.matrix_ == nullptr) {
    throw("Matrix is not empty !!!");
  } else if ((this->rows_ < 1 || this->columns_ < 1) ||
             (other.rows_ < 1 || other.columns_ < 1)) {
    throw("Matrix size is not correct !!!");
  } else if (this->rows_ != other.rows_ || this->columns_ != other.columns_) {
    throw("Matrix sizes are not equal !!!");
  }
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->columns_; j++) {
      if (flag) {
        this->matrix_[i][j] += other.matrix_[i][j];
      } else {
        this->matrix_[i][j] -= other.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  this->ManagerSumSub(other, true);
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  this->ManagerSumSub(other, false);
}

void S21Matrix::MulNumber(const double num) {
  if (this->matrix_ == nullptr) {
    throw("Matrix is not empty !!!");
  } else if (this->rows_ < 1 || this->columns_ < 1) {
    throw("Matrix size is not correct !!!");
  }
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->columns_; j++) {
      this->matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (this->matrix_ == nullptr || other.matrix_ == nullptr) {
    throw("Matrix is not empty !!!");
  } else if ((this->rows_ < 1 || this->columns_ < 1) ||
             (other.rows_ < 1 || other.columns_ < 1)) {
    throw("Matrix size is not correct !!!");
  } else if (this->columns_ != other.rows_) {
    throw("Matrix sizes are not equal !!!");
  }
  S21Matrix result(this->rows_, other.columns_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < other.columns_; j++) {
      for (int k = 0; k < other.rows_; k++) {
        result.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = result;
}

double S21Matrix::Determinant() {
  if (this->matrix_ == nullptr) {
    throw("Matrix is not empty !!!");
  } else if (this->rows_ < 1 || this->columns_ < 1) {
    throw("Matrix size is not correct !!!");
  } else if (this->rows_ != this->columns_) {
    throw("Matrix rows and columns are not equal !!!");
  }
  double result = 0;
  if (this->rows_ == 1) {
    result = this->matrix_[0][0];
  } else if (this->rows_ == 2) {
    result = this->matrix_[0][0] * this->matrix_[1][1] -
             this->matrix_[1][0] * this->matrix_[0][1];
  } else {
    double tmp = 0;
    for (int i = 0; i < this->rows_; i++) {
      S21Matrix minor(this->rows_ - 1, this->columns_ - 1);
      this->Minor(minor, 0, i);
      tmp += this->matrix_[i][0] * pow(-1, i) * minor.Determinant();
      result = tmp;
    }
  }
  return result;
}

S21Matrix S21Matrix::Transpose() {
  if (this->matrix_ == nullptr) {
    throw("Matrix is not empty !!!");
  } else if (this->rows_ < 1 || this->columns_ < 1) {
    throw("Matrix size is not correct !!!");
  }
  S21Matrix result(this->columns_, this->rows_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->columns_; j++) {
      result.matrix_[j][i] = this->matrix_[i][j];
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (this->matrix_ == nullptr) {
    throw("Matrix is not empty !!!");
  } else if (this->rows_ < 1 || this->columns_ < 1) {
    throw("Matrix size is not correct !!!");
  } else if (this->rows_ != this->columns_) {
    throw("Matrix rows and columns are not equal !!!");
  }
  S21Matrix result(this->rows_, this->columns_);
  S21Matrix minor(this->rows_ - 1, this->columns_ - 1);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->columns_; j++) {
      this->Minor(minor, j, i);
      result.matrix_[i][j] = pow(-1, i + j) * minor.Determinant();
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (this->matrix_ == nullptr) {
    throw("Matrix is not empty !!!");
  } else if (this->rows_ < 1 || this->columns_ < 1) {
    throw("Matrix size is not correct !!!");
  } else if (this->rows_ != this->columns_) {
    throw("Matrix rows and columns are not equal !!!");
  }
  double det = this->Determinant();
  if (det < 1e-7) {
    throw("Determinant equal to nil !!!");
  }
  S21Matrix result(this->rows_, this->columns_);
  S21Matrix tmp(this->rows_, this->columns_);
  if (this->rows_ == 1) {
    result.matrix_[0][0] = 1.0 / this->matrix_[0][0];
  } else {
    tmp = this->Transpose();
    result = tmp.CalcComplements();
    result.MulNumber(1.0 / det);
  }
  return result;
}

// Overload operators
S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix result(*this);
  result.MulNumber(num);
  return result;
}

S21Matrix S21Matrix::operator+=(const S21Matrix &other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator-=(const S21Matrix &other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const S21Matrix &other) {
  this->MulMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  this->ClearMatrix();
  this->CopyMatrix(other);
  return *this;
}

bool S21Matrix::operator==(const S21Matrix &other) {
  return this->EqMatrix(other);
}

double &S21Matrix::operator()(int i, int j) {
  if (i >= this->rows_ || j >= this->columns_ || i < 0 || j < 0) {
    throw("Index is not correct !!!");
  }
  return this->matrix_[i][j];
}
