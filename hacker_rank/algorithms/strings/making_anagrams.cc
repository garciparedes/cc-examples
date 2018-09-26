#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int making_anagrams(const string &text1, const string &text2) {
  int counter = 0;

  map<char, int> counter_mapper;

  for (char value: text1) {
    counter_mapper[value] += 1;
  }

  for (char value: text2) {
    counter_mapper[value] -= 1;
  }

  for (pair<char, int> value: counter_mapper) {
    counter += abs(value.second);
  }

  return counter;
}

int main() {
  string text1, text2;

  cin >> text1;
  cin >> text2;

  cout << making_anagrams(text1, text2) << '\n';

  return 0;
}