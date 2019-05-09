#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
  int q, op, temp;
  string result;
  set<int> data;

  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> op >> temp;

    if (op == 1) {
      data.insert(temp);
    } else if (op == 2) {
      data.erase(temp);
    } else if (op == 3) {
      result = (data.find(temp) != data.end()) ? "Yes" : "No";
      cout << result << '\n';
    } else {
      cout << "ERROR!" << '\n';
    }
  }
  return 0;
}



