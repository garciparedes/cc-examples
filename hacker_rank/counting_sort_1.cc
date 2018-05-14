#include <bits/stdc++.h>

using namespace std;

vector<int> countingSort(vector<int> arr) {
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
    for (int v : countingSort(arr) ) {
        cout << v << ' ';
    }
    cout << '\n';
    return 0;
}

