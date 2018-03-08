#include <bits/stdc++.h>

using namespace std;

int pickingNumbers(vector <int> a) {
    sort(a.begin(), a.end());
    int c_max = 2, c_i1 = 0, c_i2 = 0;
    for(int k = 1; k < a.size(); ++k) {
        if(a[k] - a[k - 1] == 1){
            c_i1 = c_i2;
            c_i2 = k;
        } else if (a[k] - a[k - 1] > 1) {
            c_i1 = k;
            c_i2 = k;
        }
        c_max = max(c_max, k - c_i1 + 1);
    }

    return c_max;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    int result = pickingNumbers(a);
    cout << result << endl;
    return 0;
}
