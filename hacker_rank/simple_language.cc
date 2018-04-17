#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the maximumProgramValue function below.
 */
unsigned long long int maximumProgramValue(int n) {
    long long int r = 0;
    long t;
    string op;

    for(int i = 0; i < n; i++) {
        cin >> op;
        cin >> t;
        if (op == "add" && t > 0) {
            r += t;
        } else if (op == "set" && t > r) {
            r = t;
        }
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = maximumProgramValue(n);

    cout << result << "\n";

    return 0;
}
