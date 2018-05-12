#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int gemstones(vector<string> arr) {
    unordered_set<char> global, current;
    
    unordered_set<char>::iterator it_g;
    vector<string>::iterator it_s;
    string::iterator it_c;
    
    it_s = arr.begin();
    for (it_c = it_s->begin(); it_c != it_s->end(); ++it_c) {
        global.insert(*it_c);
    } 
    for (++it_s; it_s != arr.end(); ++it_s) {
        current.clear();
        for (it_c = it_s->begin(); it_c != it_s->end(); ++it_c) {
            current.insert(*it_c);
        }
        for (it_g = global.begin(); it_g != global.end(); ) {
            if (current.find(*it_g) == global.end()) {
                it_g = global.erase(it_g);
            } else {
                ++it_g;
            }
        }
    }
    return global.size();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

