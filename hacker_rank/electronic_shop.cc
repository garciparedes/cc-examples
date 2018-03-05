#include <bits/stdc++.h>

using namespace std;

int getMoneySpent(vector < int > keyboards, vector < int > drives, int s){
    sort(keyboards.begin(), keyboards.end());
    sort(drives.begin(), drives.end());

    int max_s = 0, i = 0, j = 0, j_max;
    bool stop_i, stop_j;

    while(j + 1 < drives.size() && (keyboards[i] + drives[j + 1]) <= s) {
        j += 1;
    }
    j_max = j;
    max_s = keyboards[i] + drives[j];
    if (s < max_s) {
        return - 1;
    } else {
        stop_i = 0;
        stop_j = 0;
        i += 1;
        while (i < keyboards.size() && !stop_i) {
            j = j_max;
            stop_j = 0;
            while(0 <= j && !stop_j) {
                if (s < keyboards[i] + drives[j]) {
                    j_max -= 1;
                } else {
                    if (max_s < keyboards[i] + drives[j]) {
                        max_s = keyboards[i] + drives[j];
                        stop_j = 1;
                        if (max_s == s) {
                            stop_i = 1;
                        }
                    }
                }
                j -= 1;
            }
            i += 1;
            if (s < keyboards[i] + drives[0]) {
                stop_i = 1;
            }
        }
        return max_s;
    }
}

int main() {
    int s;
    int n;
    int m;
    cin >> s >> n >> m;
    vector<int> keyboards(n);
    for(int keyboards_i = 0; keyboards_i < n; keyboards_i++){
       cin >> keyboards[keyboards_i];
    }
    vector<int> drives(m);
    for(int drives_i = 0; drives_i < m; drives_i++){
       cin >> drives[drives_i];
    }
    //  The maximum amount of money she can spend on a keyboard and USB drive, or -1 if she can't purchase both items
    int moneySpent = getMoneySpent(keyboards, drives, s);
    cout << moneySpent << endl;
    return 0;
}
