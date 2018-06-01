#include <bits/stdc++.h>

using namespace std;

int chocolateFeast(int n, int c, int m) {
    int cnt = n / c, t1 = cnt, t2;
    while(t1 >= m) {
        t2 = t1 / m;
        cnt += t2;
        t1 = t1 % m + t2;
    }
    return cnt;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int c;
        int m;
        cin >> n >> c >> m;
        int result = chocolateFeast(n, c, m);
        cout << result << endl;
    }
    return 0;
}

