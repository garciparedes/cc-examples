#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int count_matches(string s, char c) {
  int cnt1 = 0, cnt2 = 0;
  cnt2 = *s.begin() == c;
  for (auto it = s.begin() + 1; it != s.end(); it++) {
    if (*(it - 1) == *(it)) {
      cnt2 += *it == c;
    } else {
      cnt1 = max(cnt1, cnt2);
      cnt2 = *it == c;
    }
  }
  return max(cnt1, cnt2);
}

vector<string> weighted_uniform_strings(const string &s, vector<long> queries) {
  vector<string> result(queries.size());
  unordered_set<long> uSet('z' - 'a' + 1);
  int i, m;
  for (char c = 'a'; c <= 'z'; ++c) {
    m = count_matches(s, c);
    for (i = 1; i <= m; i++) {
      uSet.insert((c - 'a' + 1) * i);
    }
  }
  for (i = 0; i < queries.size(); i++) {
    result[i] = (uSet.find(queries[i]) != uSet.end() ? "Yes" : "No");
  }
  return result;
}

int main() {
  unsigned long q_n;
  string s;
  cin >> s;
  cin >> q_n;
  vector<long> queries(q_n);
  for (int i = 0; i < q_n; i++) {
    cin >> queries[i];
  }
  for (const string &v : weighted_uniform_strings(s, queries)) {
    cout << v << '\n';
  }
  return 0;
}
