#include <iostream>

using namespace std;

class Box {
 private:
  int l;
  int b;
  int h;

 public:
  Box()
      : l(0),
        b(0),
        h(0) {}

  Box(int length, int breadth, int height)
      : l(length),
        b(breadth),
        h(height) {}

  Box(Box &box)
      : l(box.getLength()),
        b(box.getBreadth()),
        h(box.getHeight()) {}

  int getLength() {
    return l;
  }

  int getBreadth() {
    return b;
  }

  int getHeight() {
    return h;
  }

  long long CalculateVolume() {
    return ((long long) l) * b * h;
  }

  bool operator<(Box &box) {
    return (l < box.l) ||
        ((l == box.l) && (b < box.b)) ||
        ((l == box.l) && (b < box.b) && (h < box.h));
  }

  friend ostream &operator<<(ostream &out, Box &box) {
    out << box.getLength() << ' ' << box.getBreadth() << ' ' << box.getHeight();
    return out;
  }
};

int main() {
  Box b(1, 1, 1);

  Box b2(b);

  cout << b2 << '\n';
}



