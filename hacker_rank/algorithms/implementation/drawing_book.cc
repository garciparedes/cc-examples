#include <bits/stdc++.h>

using namespace std;

int solve(int n, int p){
    return min(p, (n - p + ((n + 1) % 2))) / 2;
}

int main() {
    int n;
    cin >> n;
    int p;
    cin >> p;
    int result = solve(n, p);
    cout << result << endl;
    return 0;
}
