#include <bits/stdc++.h>
#include <string>

using namespace std;



string pangrams(string s) {
    bool result = false;
    set<char> m;
    const int l = 'z' - 'a' + 1;

    string::iterator it_s = s.begin();
    while(it_s != s.end() && m.size() != l) {
       if (('a' <= *it_s && *it_s <= 'z') ||
               ('A' <= *it_s && *it_s <= 'Z')) {
           m.insert(tolower(*it_s));
       }
       ++it_s;
    }
    
    return (m.size() == l ? "pangram" : "not pangram");
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << '\n';

    fout.close();

    return 0;
}

