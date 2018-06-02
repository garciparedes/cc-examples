
#include <vector>
#include <iostream>

using namespace std;

unsigned long surface_area(vector<vector<int>> A) {
    int i, j;
    unsigned long r = A.size() * A[0].size() * 2;
    for (i = 0; i < A.size(); i++) {
        r += A[i][0] + A[i][A[0].size() - 1];
    }
    for (j = 0; j < A[0].size(); j++) {
        r += A[0][j] + A[A.size() - 1][j];
    }
    for (i = 0; i < A.size(); i++) {
        for (j = 0; j < A[0].size(); j++) {
            if (i + 1 < A.size()) {
                r += abs(A[i][j] - A[i + 1][j]);
            }
            if (j + 1 < A[0].size()) {
                r += abs(A[i][j] - A[i][j + 1]);
            }
        }
    }
    return r;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    cout << surface_area(A) << endl;
    return 0;
}
