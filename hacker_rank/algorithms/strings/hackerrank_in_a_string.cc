#include <bits/stdc++.h>

using namespace std;

const string p = "hackerrank";

string hackerrank_in_string(string s) {
    auto it_p = p.begin();
    auto it_s = s.begin();
    while(it_p != p.end() && it_s != s.end()) {
        if (*it_p == *it_s) {
            ++it_p;
        }
        ++it_s;
    }
    return (it_p == p.end() ? "YES" : "NO");
}

int main() {
    int q;
    string s;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        cin >> s;
        cout << hackerrank_in_string(s) << '\n';
    }
    return 0;
}
