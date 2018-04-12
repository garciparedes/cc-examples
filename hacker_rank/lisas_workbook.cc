#include <bits/stdc++.h>

using namespace std;

int workbook(int k, vector <int> arr) {
    int cnt = 0, page = 0, t1, t2;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        t1 = 1;
        while (*it > 0) {
            t2 = min(*it, k);
            cnt += (t1 <= ++page && page < (t1 + t2) ? 1 : 0);
            t1 += t2;
            *it -= t2;
        }
    }
    return cnt;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = workbook(k, arr);
    cout << result << endl;
    return 0;
}
