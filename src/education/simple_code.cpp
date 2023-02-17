
#include "simple_code.h"
using namespace std;

class Human {
 public:
  int age;
  int weigth;
  string name;

  void Print() {
    cout << "Имя: " << name << "\tВес: " << weigth << "\tВозраст: " << age;
  }
};

class CoffeeGrinder {
 private:
  bool CheckVoltage() { return true; }

 public:
  void Start() {
    if (CheckVoltage()) {
      cout << "VjuHHH!!" << endl;
    } else {
      cout << "Beep Beep!!" << endl;
    }
  }
};

class Point {
 private:
  int x;
  int y;
  int z;

 public:
  // конструкторы
  Point() {
    x = 0;
    y = 0;
    z = 0;
  };
  Point(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
  };
  // конструктор копирования
  Point(const Point &other) {
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
  }
  // деструктор
  ~Point() {
    x = 0;
    y = 0;
    z = 0;
  };

  int GetX() { return x; }
  int GetY() { return y; }
  int GetZ() { return z; }

  void SetX(int x) { this->x = x; }
  void SetY(int y) { this->y = y; }
  void SetZ(int z) { this->z = z; }

  void Print() { cout << x << " " << y << " " << z << " " << endl; }
};

int main() {
  // Point c1;
  Point c2(1, 2, 3);
  c2.Print();
  c2.~Point();
  // c2.Print();

  // c2.Print();
  return 0;
}
