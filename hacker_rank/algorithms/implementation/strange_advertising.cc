#include <bits/stdc++.h>

using namespace std;

int viralAdvertising(int n) {
    int y_k = 2, y_k_1 = 0, y_k_2 = 0;
    for(int i = 0; i < n-1; ++i) {
        y_k_2 = y_k_1;
        y_k_1 = y_k;
        y_k = floor(5.0 / 2.0 * y_k_1 - 3.0 / 2.0 * y_k_2);
    }
    return y_k;
}

int main() {
    int n;
    cin >> n;
    int result = viralAdvertising(n);
    cout << result << endl;
    return 0;
}
