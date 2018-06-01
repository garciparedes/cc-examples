#include <bits/stdc++.h>

using namespace std;

int how_many_games(int p, int d, int m, int s) {
    int result = 0;
    while (s >= p) {
        s -= p;
        p -= (p > m ? min(d, p - m) : 0);
        result += 1;
    }
    return result;
}


int main() {
    int p, d, m, s;
    cin >> p >> d >> m >> s;
    cout << how_many_games(p, d, m, s) << endl;
    return 0;
}

