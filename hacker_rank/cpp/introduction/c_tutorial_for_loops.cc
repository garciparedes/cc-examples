#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  int left, right;
  cin >> left;
  cin >> right;
  for(int i = left; i <= right; i++) {
    if (0 < i && i < 10) {
      switch (i) {
        case 1:
          cout << "one" << endl;
          break;
        case 2:
          cout << "two" << endl;
          break;
        case 3:
          cout << "three" << endl;
          break;
        case 4:
          cout << "four" << endl;
          break;
        case 5:
          cout << "five" << endl;
          break;
        case 6:
          cout << "six" << endl;
          break;
        case 7:
          cout << "seven" << endl;
          break;
        case 8:
          cout << "eight" << endl;
          break;
        case 9:
          cout << "nine" << endl;
          break;
      }
    } else {
      switch (i % 2) {
        case 0:
          cout << "even" << endl;
          break;
        case 1:
          cout << "odd" << endl;
          break;
      }
    }
  }
  return 0;
}
