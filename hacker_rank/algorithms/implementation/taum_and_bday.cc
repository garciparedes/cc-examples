#include <bits/stdc++.h>

using namespace std;

long taumBday(long b, long w, long x, long y, long z) {
    if ((x + z) < y) {
        return x * b + (x + z) * w;
    } else if ((y + z) < x) {
        return (y + z) * b + y * w;
    } else {
        return x * b + y * w;
    }
}

int main() {
    int t;
    long result, b, w, x, y, z;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        cin >> b >> w;
        cin >> x >> y >> z;
        result = taumBday(b, w, x, y, z);
        cout << result << endl;
    }
    return 0;
}

