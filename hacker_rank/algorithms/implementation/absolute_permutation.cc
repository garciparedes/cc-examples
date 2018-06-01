#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the absolutePermutation function below.
 */
vector<int> absolutePermutation(int n, int k) {
    vector<int> result;
    if (k == 0) {
        for(int i = 1; i <= n; i++) {
            result.push_back(i);
        }
    } else if (n % k == 0 && (n / k) % 2 == 0) {
        int cnt = 0, a;
        bool side = false;
        for(int i = 1; i <= n; i++) {
            a = cnt % (2 * k);
            if (a < k) {
                result.push_back(i + k);
            } else {
                result.push_back(i - k);
            }
            cnt += 1;
        }
    } else {
        result.push_back(- 1);
    }
    return result;
}

int main() {
    int t, n, k;
    cin >> t;
    for (int t_itr = 0; t_itr < t; t_itr++) {
        cin >> n;
        cin >> k;
        vector<int> result = absolutePermutation(n, k);
        for (auto it = result.begin(); it != result.end(); ++it) {
            cout << *it << ' ';
        }
        cout << '\n';
    }
    return 0;
}
