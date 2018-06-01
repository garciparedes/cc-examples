#include <bits/stdc++.h>

using namespace std;

int running_time(vector<int> arr) {
    int v, shift_cnt = 0;
    vector<int>::iterator it_i, it_j;
    for(it_i = arr.begin(); it_i != arr.end(); ++it_i) {
        v = *it_i;
        it_j = (it_i - 1);
        while(it_j >= arr.begin() && v < *it_j) {
            *(it_j + 1) = *it_j;
            shift_cnt += 1;
            it_j -= 1;
        }
        *(it_j + 1) = v;
    }
    return shift_cnt;
}
int main(void) {

    int N, t;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << running_time(arr) << '\n';
    return 0;
}
