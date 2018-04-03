#include <bits/stdc++.h>
#include <string>
#include <cmath>

using namespace std;

vector <int> kaprekarNumbers(int p, int q) {
    vector<int> result;

    string square;
    int j;
    for(long i = p; i <= q; ++i) {
        square = to_string(i * i);
        j = square.size() / 2;
        if ((j == 0 ? 0 : stoi(square.substr(0, j))) + 
                stoi(square.substr(j, square.size())) == i) {
            result.push_back(i);
        }
        
    }

    return result;
}

int main() {
    int p;
    cin >> p;
    int q;
    cin >> q;
    vector <int> result = kaprekarNumbers(p, q);
    if (result.empty()) {
        cout << "INVALID RANGE\n";
    } else {
        for (ssize_t i = 0; i < result.size(); i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

