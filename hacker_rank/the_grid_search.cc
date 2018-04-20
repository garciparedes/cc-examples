#include <bits/stdc++.h>

using namespace std;

string gridSearch(vector <string> G, vector <string> P) {
    bool is_here = false;
    bool j_ok = false;

    size_t i1, i2, j1, j2,
        R = G.size(), C = G[0].size(),
        r = P.size(), c = P[0].size();

    i1 = 0;
    while (!is_here && i1 < R - r + 1) {
        j1 = 0;
        while (!is_here && j1 < C - c + 1) {
            i2 = 0;
            j_ok = true;
            while (i2 < r && j_ok) {
                j_ok = false;
                j2 = 0;
                while (j2 < c && G[i1 + i2][j1 + j2] == P[i2][j2]) {
                    j2 += 1;
                }
                j_ok = (j2 == c);
                i2 += 1;
            }
            is_here = (i2 == r && j_ok);
            j1 += 1;

        }
        i1 += 1;
    }
    return (is_here ? "YES" : "NO");
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0; G_i < R; G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0; P_i < r; P_i++){
           cin >> P[P_i];
        }
        string result = gridSearch(G, P);
        cout << result << endl;
    }
    return 0;
}
