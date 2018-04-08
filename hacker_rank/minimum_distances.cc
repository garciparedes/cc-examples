#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

using namespace std;

int minimumDistances(vector <int> a) {
   vector<pair<int, int>> vec(a.size());
   int i;
   for(auto it = vec.begin(); it != vec.end(); ++it) {
       i = it - vec.begin();
       it->first = a[i];
       it->second = i;
   }
   sort(vec.begin(), vec.end());
   int result = - 1;
   for(auto it = vec.begin(); it != vec.end() - 1; ++it) {
       if (it->first == (it + 1) -> first) {
           result = (result < 0 ? abs((it + 1)->second - it->second) :
                       min(abs((it + 1)->second - it->second), result));
       }
   }
   return result;
}

int main() {
   int n;
   cin >> n;
   vector<int> a(n);
   for(int a_i = 0; a_i < n; a_i++){
      cin >> a[a_i];
   }
   int result = minimumDistances(a);
   cout << result << endl;
   return 0;
}
