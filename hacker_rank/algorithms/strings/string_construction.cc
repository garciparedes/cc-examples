#include <string>
#include <iostream>
#include <set>

using namespace std;

int string_construction(string text) {
  set<char> distinct_chars;
  for (char c: text) {
    distinct_chars.insert(c);
  }
  return static_cast<int>(distinct_chars.size());
}

int main() {
  int cases, result;
  string text;

  cin >> cases;
  for (int i = 0; i < cases; i++) {
    cin >> text;
    result = string_construction(text);
    cout << result << "\n";
  }

  return 0;
}
