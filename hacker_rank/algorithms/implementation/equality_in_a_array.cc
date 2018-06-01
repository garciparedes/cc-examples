#include <bits/stdc++.h>

using namespace std;

int equalizeArray(vector <int> arr) {
    map<int, unsigned> counter;
    
    vector<int>::iterator it_vec;
    for(it_vec = arr.begin(); it_vec != arr.end(); ++it_vec) { 
        ++counter[*it_vec];
    }
    unsigned max_counter = 0;
    map<int, unsigned>::iterator it_counter;
    for(it_counter = counter.begin(); it_counter != counter.end(); ++it_counter) {
        if (max_counter < it_counter->second) {
            max_counter = it_counter->second;
        }
    }
    return arr.size() - max_counter;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = equalizeArray(arr);
    cout << result << endl;
    return 0;
}

