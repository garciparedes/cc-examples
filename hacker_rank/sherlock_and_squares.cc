#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int squares(int a, int b) {
    int l = ceil(sqrt(a)), u = floor(sqrt(b));
    return (l <= u) ? u - l + 1 : 0;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int a;
        int b;
        cin >> a >> b;
        int result = squares(a, b);
        cout << result << endl;
    }
    return 0;
}
