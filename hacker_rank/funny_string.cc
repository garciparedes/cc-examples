#include <bits/stdc++.h>

using namespace std;

string funny_string(string s){
    bool r = true;

    auto it_i = s.begin();
    auto it_j = s.end() - 1;

    while(r && it_i < it_j) {
        if (abs(*it_i  - *(it_i + 1) ) != abs(*(it_j) - *(it_j - 1)) ) {
           r = false;
        } 
        ++it_i;
        --it_j;
    }

    return (r ? "Funny" : "Not Funny");
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        cout << funny_string(s) << endl;
    }
    return 0;
}
