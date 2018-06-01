#include <bits/stdc++.h>

using namespace std;

int fairRations(vector <int> B) {
    int cnt = 0;
    vector<int>::iterator it;
    for(it = B.begin(); it != B.end() - 1; ++it) {
        if (*(it) % 2 != 0) {
            *(it) += 1;
            *(it + 1) += 1;
            cnt += 2;
        }
    }
    return (*(it) % 2 == 0 ? cnt : - 1);
}

int main() {
    int N;
    cin >> N;
    vector<int> B(N);
    for(int B_i = 0; B_i < N; B_i++){
       cin >> B[B_i];
    }
    int result = fairRations(B);
    cout << (result == - 1 ? "NO" : to_string(result))  << '\n';
    return 0;
}
