#include <bits/stdc++.h>

using namespace std;

vector<int> insertionSort(int N, vector<int> arr) {
    int v;
    vector<int>::iterator it_i, it_j;
    for(it_i = arr.begin(); it_i != arr.end(); ++it_i) {
        v = *it_i;
        it_j = (it_i - 1);
        while(it_j >= arr.begin() && v < *it_j) {
            *(it_j + 1) = *it_j;
            it_j -= 1;
        }
        *(it_j + 1) = v;
    }
    return arr;
}
int main(void) {

    int N, t;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    arr = insertionSort(N, arr);
    for(auto v : arr) {
        cout << v << ' ';
    }
    cout << '\n';
    return 0;
}
