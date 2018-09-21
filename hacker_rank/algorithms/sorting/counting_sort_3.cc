#include <vector>
#include <iostream>

using namespace std;

int main() {
  int n;
  string text;

  cin >> n;
  vector<int> counter(100, 0);

  int temp;
  for (int i = 0; i < n; i += 1) {
    cin >> temp >> text;
    counter[temp] += 1;
  }

  int cum = 0;
  for (int value: counter) {
    cum += value;
    cout << cum << ' ';
  }
  cout << '\n';

  return 0;
}
