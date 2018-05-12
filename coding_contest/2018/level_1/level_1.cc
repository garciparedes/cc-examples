#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;


bool check(vector<vector<int>> image) {

    bool result = false;
    ssize_t i, j;

    i = 0;
    while(i < image.size() - 1 && !result) {
        j = 0;
        while(j < image[i].size() - 1 && !result) {
            if (image[i][j] > 0) {
                result = true;
            }
            j++;
        }
        i++;
    }
    return result;
}

int main() {
    int t_init, t_end, n, stamp, n1, n2, s;
    vector<int> stamps;


    cin >> t_init >> t_end >> n;

    for (int c = 0; c < n; c++) {
        cin >> s >> n1 >> n2;

        vector<vector<int>> image(n1, vector<int>(n2));
        for(int i = 0; i < n1; i++) {
            for(int j = 0; j < n2; j++) {
                cin >> image[i][j];
            }
        }
        if( t_init <= s && s <= t_end && check(image) ){
            stamps.push_back(s);
        }

    }

    for( int v : stamps) {
        cout << v << '\n';
    }

    return 0;
}
