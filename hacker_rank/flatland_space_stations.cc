#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int flatlandSpaceStations(int n, vector<int> c) {
    int max_dist = 0;
    sort(c.begin(), c.end());
    if (n == c.size()){
        return 0;
    } else {
        max_dist = max(*c.begin(), n - *(c.end() - 1) - 1);
        for(auto it = c.begin(); it != c.end() - 1; ++it) {
            max_dist = max((*(it + 1) - *it) / 2 , max_dist);
        }
    }
    return max_dist;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    int result = flatlandSpaceStations(n, c);
    cout << result << endl;
    return 0;
}
