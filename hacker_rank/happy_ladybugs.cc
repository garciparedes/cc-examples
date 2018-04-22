#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

/*
 * Complete the happyLadybugs function below.
 */
string happyLadybugs(string b) {
    bool result = true;
    if (b.size() > 1) {
        unordered_map<char, int> counter;

        bool adj = *b.begin() == *(b.begin() + 1);
        counter[*b.begin()] += 1;
        for(auto it_b = b.begin() + 1; it_b < b.end() - 1; it_b++) {
            counter[*it_b] += 1;
            adj = adj && (*it_b == *(it_b - 1) || *it_b == *(it_b + 1));
        }
        counter[*(b.end() - 1)] += 1;
        adj = adj && *(b.end() - 2) == *(b.end() - 1);

        if (counter['_'] > 0) {
            auto it_c = counter.begin();
            while(it_c != counter.end() && result) {
                result = it_c->second > 1 || it_c->first == '_';
                ++it_c;
            }
        } else {
            result = adj;
        }
    } else if (b[0] != '_'){
        result = false;
    }

    return (result ? "YES" : "NO");
}

int main() {
    int g, n;
    string b;
    cin >> g;
    for (int g_itr = 0; g_itr < g; g_itr++) {
        cin >> n;
        cin >> b;
        string result = happyLadybugs(b);
        cout << result << "\n";
    }

    return 0;
}
