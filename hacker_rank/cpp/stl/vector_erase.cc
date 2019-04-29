#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, temp, x, a, b;
    vector<int> vec;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        vec.push_back(temp);
    }
    cin >> x;
    cin >> a >> b;

    vec.erase(vec.begin() + x - 1);
    vec.erase(vec.begin() + a - 1, vec.begin() + b - 1);

    cout << vec.size() << '\n';
    for (int k : vec) {
        cout << k << ' ';
    }
    cout << '\n';

    return 0;
}
