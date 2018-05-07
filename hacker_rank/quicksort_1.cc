#include <bits/stdc++.h>

using namespace std;

vector <int> quick_sort(vector <int> arr) {
    vector<int> left;
    vector<int> right;
    vector<int>::iterator it_p = arr.begin();
    vector<int>::iterator it_i;
    for (it_i = it_p + 1; it_i < arr.end(); ++it_i) {
        if (*it_i < *it_p) {
            left.push_back(*it_i);
        } else {
            right.push_back(*it_i);
        }
    }
    vector<int> result;
    for(it_i = left.begin(); it_i < left.end(); it_i++){
        result.push_back(*it_i);
    }
    result.push_back(*it_p);
    for(it_i = right.begin(); it_i < right.end(); it_i++){
        result.push_back(*it_i);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    vector <int> result = quick_sort(arr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    cout << '\n';


    return 0;
}
