#include <bits/stdc++.h>

using namespace std;

vector<int> stones(int n, int a, int b) {
    vector<int> result;
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    int s = (n - 1) * a;
    int s_max = (n - 1) * b;
    result.push_back(s);
    while (s < s_max) {
        s += b - a;
        result.push_back(s);
    }
    return result;
}

int main() {
    int T, n, a, b;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        cin >> n;
        cin >> a;
        cin >> b;
        vector <int> result = stones(n, a, b);
        for (ssize_t i = 0; i < result.size(); i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
