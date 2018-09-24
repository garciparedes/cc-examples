#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int the_love_letter_mystery(string text) {
  int result = 0;
  for (int i = 0; i < text.size() / 2; i += 1) {
    result += abs(text[i] - text[text.size() - i - 1]);
  }
  return result;
}

int main() {
  int cases;

  cin >> cases;

  string text;
  for (int i = 0; i < cases; i += 1) {
    cin >> text;
    cout << the_love_letter_mystery(text) << '\n';
  }

  return 0;
}