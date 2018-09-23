#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split_string(string);

string larrys_array(const vector<int> &numbers) {

  int cnt = 0;
  for (auto it_i = numbers.begin(); it_i < numbers.end(); it_i += 1) {
    for (auto it_j = it_i + 1; it_j < numbers.end(); it_j += 1) {
      cnt += *it_i > *it_j;
    }
  }

  return (cnt % 2 == 0) ? "YES" : "NO";
}

int main() {

  int cases;
  cin >> cases;

  unsigned long n;
  for (int c = 0; c < cases; c++) {
    cin >> n;

    int number;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
      cin >> number;
      numbers[i] = number;
    }
    string result = larrys_array(numbers);
    cout << result << '\n';
  }

  return 0;
}