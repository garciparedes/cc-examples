#include <bits/stdc++.h>

using namespace std;

vector<int> serviceLane(vector<int> width, vector<vector<int>> cases) {
    vector<int> out(cases.size());
    vector<vector<int>>::iterator cases_it;
    vector<int>::iterator out_it;
    for (cases_it = cases.begin(), out_it = out.begin(); 
            cases_it != cases.end() && out_it != out.end(); 
            ++cases_it, ++out_it) {
        *out_it = *min_element(width.begin() + cases_it->at(0), 
                width.begin() + cases_it->at(1) + 1);
    }
    return out;
}

int main() {
    int n;
    int t;
    cin >> n >> t;
    vector<int> width(n);
    for(int width_i = 0; width_i < n; width_i++){
       cin >> width[width_i];
    }
    vector<vector<int>> cases(t, vector<int>(2));
    for (int cases_i = 0; cases_i < t; cases_i++){
       for (int cases_j = 0; cases_j < 2; cases_j++){
          cin >> cases[cases_i][cases_j];
       }
    }
    vector <int> result = serviceLane(width, cases);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
    return 0;
}

