#include <bits/stdc++.h>
#include <cmath>

using namespace std;

vector<vector<int>> obstacle_remover(int i, int j, vector<vector<int>> obstacles) {
    vector<vector<int>> new_obstacles(8, vector<int>(2, 0));
    int ii, jj;
    for (auto it = obstacles.begin(); it != obstacles.end(); ++it) {
        ii = it->at(0), jj = it->at(1);
        if (ii == i) {
            if (jj < j) {
                if (new_obstacles[6][1] == 0 || new_obstacles[6][1] < jj) {
                    new_obstacles[6][1] = jj;
                }
            } else {
                if (new_obstacles[2][1] == 0 || new_obstacles[2][1] > jj) {
                    new_obstacles[2][1] = jj;
                }
            }
        } else if (jj == j){
            if (ii < i) {
                if (new_obstacles[0][0] == 0 || new_obstacles[0][0] < ii) {
                    new_obstacles[0][0] = ii;
                }
            } else {
                if (new_obstacles[4][0] == 0 || new_obstacles[4][0] > ii) {
                    new_obstacles[4][0] = ii;
                }
            }
        } else if (abs(ii - i) == abs(jj - j)) {
            if (ii < i) {
                if (jj < j) {
                    if (new_obstacles[7][0] == 0 || new_obstacles[7][0] < ii) {
                        new_obstacles[7][0] = ii;
                        new_obstacles[7][1] = jj;
                    }
                } else {
                    if (new_obstacles[1][0] == 0 || new_obstacles[1][0] < ii) {
                        new_obstacles[1][0] = ii;
                        new_obstacles[1][1] = jj;
                    }
                }
            } else {
                if (jj < j) {
                    if (new_obstacles[5][1] == 0 || new_obstacles[5][0] > ii) {
                        new_obstacles[5][0] = ii;
                        new_obstacles[5][1] = jj;
                    }
                } else {
                    if (new_obstacles[3][1] == 0 || new_obstacles[3][0] > ii) {
                        new_obstacles[3][0] = ii;
                        new_obstacles[3][1] = jj;
                    }
                }
            }
        }
    }
    return new_obstacles;
}


int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int i, j, counter = 0;
    obstacles = obstacle_remover(r_q, c_q, obstacles);

    i = r_q - 1;
    while ( i > 0 && obstacles[0][0] != i) {
        --i, ++counter;
    }
    
    i = r_q + 1; 
    while ( i < (n + 1) && obstacles[4][0] != i) {
        ++i, ++counter;
    }
    
    j = c_q - 1;
    while ( j > 0 && obstacles[6][1] != j) {
        --j, ++counter;
    }
   
    j = c_q + 1; 
    while ( j < (n + 1) && obstacles[2][1] != j ) {
        ++j, ++counter;
    }
    
    i = r_q - 1, j = c_q - 1;
    while ( i > 0 && j > 0  && obstacles[7][0] != i && obstacles[7][1] != j ) { 
        --i, --j, ++counter;
    }

    i = r_q - 1, j = c_q + 1;
    while ( i > 0 && j < (n + 1)  && obstacles[1][0] != i && obstacles[1][1] != j ) { 
        --i, ++j, ++counter;
    }

    i = r_q + 1, j = c_q - 1;
    while ( i < (n + 1) && j > 0  && obstacles[5][0] != i && obstacles[5][1] != j ) { 
        ++i, --j, ++counter;
    }
    
    i = r_q + 1, j = c_q + 1;
    while ( i < (n + 1) && j < (n + 1) && obstacles[3][0] != i && obstacles[3][1] != j) { 
        ++i, ++j, ++counter;
    }

    return counter;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    int r_q;
    int c_q;
    cin >> r_q >> c_q;
    vector< vector<int> > obstacles(k,vector<int>(2));
    for(int obstacles_i = 0;obstacles_i < k;obstacles_i++){
       for(int obstacles_j = 0;obstacles_j < 2;obstacles_j++){
          cin >> obstacles[obstacles_i][obstacles_j];
       }
    }
    int result = queensAttack(n, k, r_q, c_q, obstacles);
    cout << result << endl;
    return 0;
}

