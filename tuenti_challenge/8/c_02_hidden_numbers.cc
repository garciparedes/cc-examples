#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/**
 *
 * Not correct due to big integer problem
 **/


unsigned long long decipher(unsigned long long b) {
    long r = 0;
    long t_min, t_max;

    t_max = 0;
    for (long i = 0; i < b; i++) {
        t_max += i * pow(b, i);
    }

    t_min = pow(b, b - 1);
    for (long i = 2; i < b; i++) {
        t_min += i * pow(b, b - 1 - i);
    }

    return t_max - t_min;
}

int main() {
    int c;
    string s;
    cin >> c;

    for(int i = 0; i < c; i++) {
        cin >> s;
        cout << "Case #" << i + 1 << ": " << decipher(s.size()) << '\n';
    }

    return 0;
}
