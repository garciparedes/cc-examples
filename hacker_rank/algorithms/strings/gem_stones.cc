#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int gem_stones(vector<string> arr) {
    unordered_set<char> global, current;
    
    unordered_set<char>::iterator it_g;
    vector<string>::iterator it_s;
    string::iterator it_c;
    
    it_s = arr.begin();
    for (it_c = it_s->begin(); it_c != it_s->end(); ++it_c) {
        global.insert(*it_c);
    } 
    for (++it_s; it_s != arr.end(); ++it_s) {
        current.clear();
        for (it_c = it_s->begin(); it_c != it_s->end(); ++it_c) {
            current.insert(*it_c);
        }
        for (it_g = global.begin(); it_g != global.end(); ) {
            if (current.find(*it_g) == global.end()) {
                it_g = global.erase(it_g);
            } else {
                ++it_g;
            }
        }
    }
    return global.size();
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (ssize_t i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << gem_stones(arr) << '\n';
    return 0;
}

