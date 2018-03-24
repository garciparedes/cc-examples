#include <bits/stdc++.h>

using namespace std;

long repeatedString(string s, long n) {
    int count = 0, s_len = s.size();
    vector<int> cum(s_len + 1, 0);
    for (int i = 0; i < s_len; ++i) {
        if (s[i] == 'a') {
            count += 1;
        }
        cum[i + 1] = count;  
    }
    return n / s_len * count + cum[(n % s_len)];
}


int main() {
    string s;
    cin >> s;
    long n;
    cin >> n;
    long result = repeatedString(s, n);
    cout << result << endl;
    return 0;
}

