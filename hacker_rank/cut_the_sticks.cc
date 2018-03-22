#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

vector <int> cutTheSticks(vector <int> arr) {
    vector<int> result;
    vector<int>::iterator it_arr;
    sort(arr.begin(), arr.end());
    while(!arr.empty()) {
        result.push_back(arr.size());
        it_arr = arr.begin();
        while(*it_arr == *arr.begin() && it_arr != arr.end()) {
            ++it_arr;
        }
        arr.erase(arr.begin(), it_arr);
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
    vector <int> result = cutTheSticks(arr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }

    return 0;
}

