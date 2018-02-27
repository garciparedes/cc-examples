#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string do_query(string data, string query) {
    return query;
}


int main() {

    int N, Q, i;
    string data, temp_str;
    cin >> N >> Q >> ws;

    for(i = 0; i < N; i++) {
        getline(cin, temp_str);
        data = data + temp_str;
    }

    cout << data << endl;


    for(i = 0; i < Q; i++) {
        getline(cin, temp_str);
        cout << do_query(data, temp_str) << endl;
    }


    return 0;
}
