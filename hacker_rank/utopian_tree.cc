#include <bits/stdc++.h>

using namespace std;

int utopianTree(int n) {
    if (n == 0) {
        return 1;
    } else {
        if (n % 2 != 0) {
            return utopianTree(n - 1) * 2;
        } else {
            return utopianTree(n - 1) + 1;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int result = utopianTree(n);
        cout << result << endl;
    }
    return 0;
}
