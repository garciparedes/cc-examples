#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

bool compare_as_ints(pair<int, string> elem_a, pair<int, string> elem_b) {
  return (elem_a.first < elem_b.first);
}

string generate_text(vector<pair<int, string>> words) {
  stringstream ss;

  stable_sort(words.begin(), words.end(), compare_as_ints);

  for (pair<int, string> elem : words) {
    ss << elem.second << ' ';
  }

  return ss.str();
}

int main() {
  unsigned long n;
  string text;

  cin >> n;
  vector<pair<int, string>> words;

  int num;
  for (int i = 0; i < n; i += 1) {
    cin >> num >> text;
    if (i < n / 2) {
      text = '-';
    }
    words.emplace_back(num, text);
  }

  string result;
  result = generate_text(words);

  cout << result << '\n';

  return 0;
}
