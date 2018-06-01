#include <bits/stdc++.h>

using namespace std;

int countingValleys(int n, string s) {
    int v = 0, deep = 0;
    for(int i = 0; i < n; ++i) {
        if (s[i] == 'D') {
            deep -= 1;
        } else {
            if (i != 0 && deep == -1) {
                v += 1;
            }
            deep += 1;
        }
    }
    return v;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int result = countingValleys(n, s);
    cout << result << endl;
    return 0;
}
