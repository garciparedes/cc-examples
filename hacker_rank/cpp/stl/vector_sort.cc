#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;

  int t;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> t;
    v.push_back(t);
  }

  sort(v.begin(), v.end());

  for (int k : v) {
    cout << k << ' ';
  }
  cout << '\n';

  return 0;
}
