#include <bits/stdc++.h>

using namespace std;

int beautifulTriplets(int d, vector <int> arr) {

    int counter = 0;
    vector<int>::iterator it_i, it_j, it_k;

    it_i = arr.begin();
    while(it_i != arr.end()) {
        it_j = it_i + 1;
        while(it_j != arr.end() && *it_j - *it_i <= d) {
            it_k = it_j + 1;
            while(*it_j - *it_i == d && it_k != arr.end()
                    && *it_k - *it_j <= d) {
                counter += (*it_k - *it_j == d ? 1 : 0);
                ++it_k;
            }
            ++it_j;
        }
        ++it_i;
    }
    return counter;
}

int main() {
    int n;
    int d;
    cin >> n >> d;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = beautifulTriplets(d, arr);
    cout << result << endl;
    return 0;
}
