#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <utility>
#include <tuple>

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


vector<pair<int,int>> extract_shape(vector<vector<int>> image) {

    vector<pair<int, int>> shape;
    int ii = -1;
    int jj = -1;
    for (int i = 0; i < image.size(); i++) {
        for (int j = 0; j < image[0].size(); j++) {
            if(image[i][j] > 0) {
                if (ii < 0 && jj < 0) {
                    ii = i;
                    jj = j;
                }
                shape.push_back(make_pair(i - ii, j - jj));
            }
        }
    }
    return shape;
}

bool is_equal(vector<pair<int,int>> s1, vector<pair<int,int>> s2){
    bool result = false;

    if (s1.size() == s2.size()) {
        result = true;
        int i, n = s1.size();

        i = 0;
        while(i < n && result) {
            result = s1[i].first == s2[i].first && s1[i].second == s2[i].second;
            i += 1;
        }
    }
    return result;


}
int main() {
    int t_init, t_end, n, stamp, n1, n2, s;
    bool is_added;
    vector<tuple<vector<pair<int, int>>, int, int, int>> shapes;

    vector<int> shapes_time;

    vector<pair<int, int>> actual_shape;

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
            is_added = false;
            actual_shape = extract_shape(image);

            for(auto it = shapes.begin(); it != shapes.end() && !is_added; ++it) {
                if (is_equal(get<0>(*it), actual_shape)) {
                    get<2>(*it) = s;
                    get<3>(*it) += 1;
                    is_added = true;
                }
            }
            if (!is_added) {
                shapes.push_back(make_tuple(actual_shape, s, s, 1));
            }
        }
    }

    for(auto v: shapes) {
        cout << get<1>(v) << ' ' << get<2>(v) << ' ' << get<3>(v) << '\n';
    }

    return 0;
}
