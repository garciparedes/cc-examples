#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n, k, i, temp, paid, need_to_pay, total = 0;
    char ws = ' ';
    cin >> n >> k;
    for (i = 0; i < n; i++) {
        cin >> temp;
        if (i != k) {
            total = total + temp;
        }
    }
    cin >> paid;
    need_to_pay = total / 2;
    if (paid == need_to_pay) {
        cout << "Bon Appetit" << endl;
    } else {
        cout <<  paid - need_to_pay << endl;
    }
    return 0;
}
