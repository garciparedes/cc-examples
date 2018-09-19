#include <iostream>
#include <sstream>
#include <string>
using namespace std;

unsigned long long int sub_to_int(const string &text, size_t i, size_t offset) {
  return stoull(text.substr(i, offset));
}

string separate_numbers(const string &text) {
  stringstream ss;
  unsigned long long int first = 0, next;
  bool beauty = false;

  size_t i, offset;

  offset = 1;
  while (offset * 2 <= text.size() && !beauty) {
    i = 0;
    first = sub_to_int(text, i, offset);
    next = first;

    while (i < text.size() && sub_to_int(text, i, to_string(next).size()) == next) {
      i += to_string(next).size();
      next += 1;
    }
    if (i == text.size()) {
      beauty = true;
    }

    offset += 1;
  }

  if (beauty) {
    ss << "YES " << first;
  } else {
    ss << "NO";
  }

  return ss.str();
}

int main() {
  int q;
  string text;
  cin >> q;
  for (int q_itr = 0; q_itr < q; q_itr++) {
    cin >> text;
    cout << separate_numbers(text) << '\n';
  }

  return 0;
}
