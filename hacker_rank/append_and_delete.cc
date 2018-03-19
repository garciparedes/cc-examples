#include <bits/stdc++.h>
#include <cmath>

using namespace std;

string appendAndDelete(string s, string t, int k) {
		bool result;
		int s_size = s.size(), t_size = t.size();
		
    if (abs(s_size - t_size) > k) {
		    result = false;
		} else if (s_size + t_size <= k) {
				result = true;		
		} else {
				auto s_it = s.begin();
				auto t_it = t.begin();
				while(s_it != s.end() && t_it != t.end() && *s_it == *t_it) {
				    ++s_it;
						++t_it;
				}
				int d = distance(s_it, s.end()) + distance(t_it, t.end());
				if (d <= k && (d - k) % 2 == 0 ) {
				    result = true;
				} else {
						result = false;
				}
		}
		return (result) ? "Yes" : "No";
}

int main() {
    string s;
    cin >> s;
    string t;
    cin >> t;
    int k;
    cin >> k;
    string result = appendAndDelete(s, t, k);
    cout << result << endl;
    return 0;
}

