#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n, k, value, idx;
  string status;
  vector<int> arr;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> value;
    arr.push_back(value);
  }

  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> value;
    auto first = lower_bound(arr.begin(), arr.end(), value);

    status = (*(first) == value) ? "Yes" : "No";
    idx = first - arr.begin() + 1;
    cout << status << ' ' << idx << '\n';
  }

  return 0;
}
