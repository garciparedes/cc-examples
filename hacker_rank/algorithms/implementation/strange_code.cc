#include <bits/stdc++.h>
#include <cmath>
using namespace std;


long long series(int k) {
    return pow(2, (k + 1)) - 1;
}

long long strangeCounter(long long t) {
    long long a, b, r;
    int k = 0;

    a = 0;
    b = 3 * series(k);
    while (t >= b) {
        ++k;
        a = b;
        b = 3 * series(k);
    }
    r = (b - t + 1) % (b - a);
    return r != 0 ? r : b - a;
}

int main() {
    long long t;
    cin >> t;
    cout << strangeCounter(t) << "\n";
    return 0;
}
