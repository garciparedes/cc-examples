#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>

using namespace std;


bool check(vector<vector<int>> image) {
    bool result = false;
    ssize_t i, j;
    i = 0;
    while(i < image.size() && !result) {
        j = 0;
        while(j < image[i].size() && !result) {
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
            result = s1[i].first == s2[i].first + 2 - ii && s1[i].second == s2[i].second + jj;
            i += 1;
        }
    }
    return result;
}
bool sort_tuples (tuple<int, int, int> i,tuple<int, int, int> j) {
    return (get<0>(i) < get<0>(j));
}


int main() {
    int t_init, t_end, n, stamp, n1, n2, s;
    bool is_added;

    vector<pair<vector<pair<int, int>>,vector<int>>> shapes;

    vector<tuple<int, int, int>> shapes_output;

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

            for(auto it = shapes.begin(); it != shapes.end(); ++it) {
                if (is_equal(it->first, actual_shape)) {
                    it->second.push_back(s);
                    is_added = true;
                }
            }
            if (!is_added) {
                shapes.push_back(make_pair(actual_shape, vector<int>(1, s)));
            }
        }
    }


    for(auto it = shapes.begin(); it != shapes.end(); ++it) {

        vector<int> vec = it->second;
        // cout  << "\n\n\n";
        // for(auto v : vec) {
        //     cout << v << ' ';
        // }
        // cout  << "\n\n";

        for(auto it_i = vec.begin(); it_i < vec.end(); ++it_i) {
            for(int k = 1; k < vec.size(); k++){
                if(*it_i > 0 && *(it_i + k) > 0) {
                    vector<int> vec_aux;

                    int m = *(it_i + k) - *it_i;

                    vec_aux.push_back(*(it_i));
                    vec_aux.push_back(*(it_i + k));

                    for(auto it_j = it_i + k + 1; it_j < vec.end(); ++it_j) {
                        if (*it_j >= 0 && (*it_j - *vec_aux.rbegin()) == m) {
                            vec_aux.push_back(*it_j);
                        }
                    }

                    if (vec_aux.size() > 3 && *vec_aux.rbegin() + m >= t_end && *vec_aux.begin() - m <= 0) {
                        shapes_output.push_back(make_tuple(*vec_aux.begin(), *vec_aux.rbegin(), vec_aux.size()));

                        for(auto v : vec_aux) {
                            *find(vec.begin(), vec.end(), v) = -1;
                            //cout << v << ' ';
                        }
                        //cout  << '\n';
                    }
                }
            }
        }
    }
    sort(shapes_output.begin(), shapes_output.end(), sort_tuples);

    for(auto v : shapes_output) {
        cout << get<0>(v) << ' ' << get<1>(v) << ' ' << get<2>(v) << '\n';
    }


    return 0;
}
