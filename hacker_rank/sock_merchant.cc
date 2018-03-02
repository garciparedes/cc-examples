#include <bits/stdc++.h>
#include <map>

using namespace std;

int sockMerchant(int n, vector <int> ar) {
    map<int,int> cnt;
    int pairs = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt[ar[i]] == 0) {
            cnt[ar[i]] += 1;
        } else {
            cnt[ar[i]] -= 1;
            pairs += 1;
        }
    }
    return pairs;
}


int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = sockMerchant(n, ar);
    cout << result << endl;
    return 0;
}
