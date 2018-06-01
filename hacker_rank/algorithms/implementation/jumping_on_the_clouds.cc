#include <bits/stdc++.h>

using namespace std;

int jumpingOnClouds(vector <int> c) {
    vector<int>::iterator it = c.begin();
    int jumps = 0;
    while ((it + 1) != c.end()) {
        if((it + 2) != c.end() && *(it + 2) != 1) {
            it += 2;
        } else {
            it += 1;
        }
        jumps += 1;
    }
    return jumps;
}

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for(int c_i = 0; c_i < n; c_i++){
       cin >> c[c_i];
    }
    int result = jumpingOnClouds(c);
    cout << result << endl;
    return 0;
}
