#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ALPHABET_LEN ('z' - 'a')

bool is_anagram(const string &text_1, const string &text_2) {

  vector<int> histogram_1(ALPHABET_LEN, 0);
  vector<int> histogram_2(ALPHABET_LEN, 0);

  for (char c : text_1) {
    histogram_1[c - 'a'] += 1;
  }
  for (char c : text_2) {
    histogram_2[c - 'a'] += 1;
  }

  bool result = true;
  int i = 0;
  while (result && i < ALPHABET_LEN) {
    result = (histogram_1[i] == histogram_2[i]);
    i += 1;
  }

  return result;
}

int sherlock_and_anagrams(const string &text) {
  int counter = 0;

  string text_1, text_2;
  // i indexes the size
  for (u_long i = 1; i < text.size(); i += 1) {
    // j indexes the initial position of first value
    for (u_long j = 0; j < text.size() - i; j += 1) {
      // k indexes the initial position of second value
      for (u_long k = j + 1; k < text.size() - i + 1; k += 1) {
        text_1 = text.substr(j, i);
        text_2 = text.substr(k, i);
        counter += is_anagram(text_1, text_2);
      }
    }
  }
  return counter;
}

int main() {
  int cases;
  cin >> cases;

  string text;

  for (int i = 0; i < cases; i += 1) {
    cin >> text;
    cout << sherlock_and_anagrams(text) << '\n';
  }
  return 0;
}
