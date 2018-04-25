#include <bits/stdc++.h>
#include <climits>

using namespace std;

string caesar_cipher(string s, short k) {
    for(auto c = s.begin(); c != s.end(); ++c){
        if ('a' <= *c && *c <= 'z') {
            *c = 'a' + (*c + k - 'a') % ('z' - 'a' + 1);
        } else if ('A' <= *c && *c <= 'Z') {
            *c = 'A' + (*c + k - 'A') % ('Z' - 'A' + 1);
        }
    }
    return s;
}

int main() {
    int n;
    string s;
    short k;
    cin >> n;
    cin >> s;
    cin >> k;
    string result = caesar_cipher(s, k);
    cout << result << '\n';
    return 0;
}
