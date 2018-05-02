#include <bits/stdc++.h>

using namespace std;

int marsExploration(string s) {
    int result = 0;
    for (int i = 0; i < s.size(); ++i) {
        result += ((i % 3 == 0 || i % 3 == 2) && s[i] != 'S') ||
                    (i % 3 == 1 && s[i] != 'O');
    }
    return result;
}

int main() {
    string s;
    cin >> s;
    int result = marsExploration(s);
    cout << result << endl;
    return 0;
}
