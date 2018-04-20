#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


struct my_hash {
    size_t operator()(const std::pair<int, int>& p) const {
        return hash<int>{}(p.first) ^ hash<int>{}(p.second);
    }
};

/*
 * Complete the dynamicLineIntersection function below.
 */
void dynamic_line_intersection(int n) {

    unordered_map<pair<int, int>, int, my_hash> lines;
    char op;
    int cuts, k, b, q;
    pair<int, int> eq;
    unordered_map<pair<int, int>, int, my_hash>::iterator it;
    for(int i = 0; i < n; i++){
        cin >> op;
        if (op == '+') {
            cin >> eq.first;
            cin >> eq.second;
            //cout << op << '\t' << k << '\t' << b << '\n';
            it = lines.find(eq);
            if (it != lines.end()) {
                it->second += 1;
            } else {
                lines[eq] = 1;
            }
        } else if (op == '-') {
            cin >> eq.first;
            cin >> eq.second;

            //cout << op << '\t' << k << '\t' << b << '\n';
            it = lines.find(eq);
            it->second -= 1;
            if(it->second < 1){
                lines.erase(it);
            }

        } else {
            cuts = 0;
            cin >> q;
            //cout << op << '\t' << q << '\n';
            for (it = lines.begin(); it != lines.end(); ++it) {
                if ( (q - it->first.second) % it->first.first == 0) {
                    cuts += 1;
                }
            }
            cout << cuts << '\n';
        }
        //cout << lines.size() << '\n';
    }

}

int main() {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');



    dynamic_line_intersection(n);

    return 0;
}
