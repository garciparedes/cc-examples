#include <bits/stdc++.h>

using namespace std;

string organizingContainers(vector<vector<int>> container) {
    bool is_possible = true;
    
    int i, j, count, n = container.size();

    vector<vector<int>> counter(3, vector<int>(n, 0));

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            counter[0][i] += container[i][j];
            counter[1][j] += container[i][j];
        }
    }
    for(i = 0; i < n && is_possible == true; i++) {
        j = 0;
        while(j < n && !(counter[2][j] == 0 && counter[1][j] == counter[0][i])) {
            j++;
        }
        if (counter[1][j] == counter[0][i] && counter[2][j] == 0) {
            counter[2][j] = 1;
        } else {
            is_possible = false;
        }
    }
    return (is_possible) ? "Possible" : "Impossible";
}


int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        cin >> n;
        vector< vector<int> > container(n,vector<int>(n));
        for(int container_i = 0;container_i < n;container_i++){
           for(int container_j = 0;container_j < n;container_j++){
              cin >> container[container_i][container_j];
           }
        }
        string result = organizingContainers(container);
        cout << result << endl;
    }
    return 0;
}

