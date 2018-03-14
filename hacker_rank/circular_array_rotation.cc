#include <bits/stdc++.h>

using namespace std;

vector <int> circularArrayRotation(vector <int> a, vector <int> m, int k) {
		int size = a.size();
		vector<int>::iterator it;
		for(it = m.begin(); it != m.end(); ++it) {
				*(it) = a[(size + ((*it - k) % size)) % size];
		}
		return m;
}

int main() {
    int n;
    int k;
    int q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> m(q);
    for(int m_i = 0; m_i < q; m_i++){
       cin >> m[m_i];
    }
    vector <int> result = circularArrayRotation(a, m, k);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
    return 0;
}

