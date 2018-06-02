#include <iostream>
#include <string>

using namespace std;

int beautiful_binary_string(string b) {
  int result = 0;
  for (auto it = b.begin() + 1; it != b.end() - 1; ++it) {
    if (*(it - 1) == '0' && *(it) == '1' && *(it + 1) == '0') {
      if ((it + 2) != b.end() && *(it + 2) == '1') {
        *(it + 1) = '1';
      } else {
        *(it) = '0';
      }
      result += 1;
    }
  }
  return result;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  cout << beautiful_binary_string(s) << '\n';
  return 0;
}