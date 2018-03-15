#include <bits/stdc++.h>

using namespace std;

vector <int> permutationEquation(vector <int> p) {
    vector<int> r(p.size());
    vector<int>::iterator it;
    for (it = p.begin(); it != p.end(); ++it) {
        r[p[p[*it - 1] - 1] - 1] = *it;
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int p_i = 0; p_i < n; p_i++){
       cin >> p[p_i];
    }
    vector <int> result = permutationEquation(p);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
    return 0;
}
