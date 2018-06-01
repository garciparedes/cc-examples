#include <bits/stdc++.h>

using namespace std;

int alternating_characters(string s) {
    int count = 0;
    char c;
    auto it = s.begin();
    c = *it;
    for (it += 1; it != s.end(); it++) {
        if (*it == c) {
            count += 1;
        } else {
            c = *it;
        }
    }
    return count;
}

int main() {
    int q;
    string s;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> s;
        cout << alternating_characters(s) << '\n';
    }
    return 0;
}
