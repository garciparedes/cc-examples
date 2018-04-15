#include <bits/stdc++.h>

using namespace std;

vector<string> cavityMap(vector<string> grid) {
    for (auto i = 1; i < grid.size() - 1; ++i) {
        for(auto j = 1; j < grid.size() - 1; ++j) {
            if (grid[i][j] > grid[i][j - 1] && grid[i][j] > grid[i][j + 1] &&
                grid[i][j] > grid[i - 1][j] && grid[i][j] > grid[i + 1][j]) {
                grid[i][j] = 'X';
            }
        }
    }
    return grid;
}

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int grid_i = 0; grid_i < n; grid_i++){
       cin >> grid[grid_i];
    }
    vector <string> result = cavityMap(grid);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
