#include <bits/stdc++.h>

using namespace std;

vector<int> counting_sort(vector<int> arr) {
    vector<int> result(100, 0);
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        result[*it] += 1;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }

    vector<int> result = counting_sort(arr);
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < result[i]; ++j) {
            cout << i << ' ';
        }
    }
    cout << '\n';
    return 0;
}

