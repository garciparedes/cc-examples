#include <string>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

bool two_strings(string s1, string s2) {
  set<char> set_1(s1.begin(), s1.end());
  set<char> set_2(s2.begin(), s2.end());

  set<char> intersect;
  set_intersection(set_1.begin(), set_1.end(),
                   set_2.begin(), set_2.end(),
                   inserter(intersect, intersect.begin()));

  return !intersect.empty();
}

int main() {
  string s1, s2;
  int q;

  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int i = 0; i < q; i++) {
    getline(cin, s1);
    getline(cin, s2);

    cout << (two_strings(s1, s2) ? "YES" : "NO") << '\n';
  }

  return 0;
}
