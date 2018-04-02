#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

string biggerIsGreater(string w) {
    string::iterator it_i = w.end(), it_j = w.end();
    while((it_i) != w.begin() && *(it_i) >= *(it_j)) {
        --it_i;
        it_j = w.end();
        while((--it_j) != (it_i) && *(it_i) >= *(it_j));
    }
    if (it_i == it_j) {
        return "no answer";
    } else {
        char temp = *it_i;
        *(it_i) = *(it_j);
        *(it_j) = temp;
        sort(it_i + 1, w.end());
        return w;
    }
}


int main() {
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        string w;
        cin >> w;
        string result = biggerIsGreater(w);
        cout << result << endl;
    }
    return 0;
}

