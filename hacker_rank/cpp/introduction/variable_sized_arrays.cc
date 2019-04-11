#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int ni, nj, qn, i, j, ii, jj, a;
  cin >> ni >> qn;
  vector<vector<int>> v(ni);

  for(i = 0; i < ni; i++) {
    scanf("%i ", &nj);
    for(j = 0; j < nj; j++) {
      scanf("%i ", &a);
      v[i].push_back(a);
    }
  }

  for(i = 0; i < qn; i++) {
    cin >> ii >> jj;
    cout << v[ii][jj] << endl;
  }
  return 0;
}
