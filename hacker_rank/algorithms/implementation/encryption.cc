#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

string encryption(string s) {
    string result;
    int rows = floor(sqrt(s.size())), columns = ceil(sqrt(s.size()));
    if (rows * columns < s.size()) {
        (rows < columns) ? rows += 1 : columns += 1;
    }
    for (int j = 0; j < columns; j++) {
        for(int i = 0; i < rows; i++) {
            if ((i * columns + j) < s.size() ){
                result += s[i * columns + j];
            }
        }
        result += ' ';
    }
    return result;
}

int main() {
    string s;
    cin >> s;
    string result = encryption(s);
    cout << result << '\n';
    return 0;
}

