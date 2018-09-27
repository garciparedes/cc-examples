#include <iostream>
#include <string>
#include <map>

using namespace std;


int anagram(const string &text) {
  if (text.size() % 2 != 0) {
    return -1;
  }

  int counter = 0;
  map<char, int> counter_mapper;
  for (char value: text.substr(0, text.size() / 2)) {
    counter_mapper[value] += 1;
  }
  for (char value: text.substr(text.size() / 2)) {
    counter_mapper[value] -= 1;
  }
  for (pair<char, int> value: counter_mapper) {
    counter += abs(value.second);
  }
  return counter / 2;
}

int main() {
  int cases;
  cin >> cases;

  string text;

  for (int i = 0; i < cases; i += 1) {
    cin >> text;
    cout << anagram(text) << '\n';
  }
  return 0;
}
