#include <iostream>

using namespace std;

long count_holes(int n, int m) {
    return (n - 1) * (m - 1);
}

int main() {
    int c, n, m;
    cin >> c;

    for(int i = 0; i < c; i++){
        cin >> n;
        cin >> m;
        cout << "Case #" << i + 1 << ": " << count_holes(n, m) << '\n';
    }

    return 0;
}
