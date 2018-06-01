#include <bits/stdc++.h>
#include <cmath>

using namespace std;


int reversed(int number) {
    int reversed = 0, temp;
    while(number > 0) {
        temp = number % 10;
        number = number / 10;
        reversed = reversed * 10 + temp;
    }
    return reversed;
}


int beautifulDays(int i, int j, int k) {
    int counter = 0;
    for (int number = i; number <= j; ++number) {
        if (fmod(static_cast<float>(number - reversed(number)) / k, 1) == 0) {
            counter += 1;
        }
    }
    return counter;
}


int main() {
    int i;
    int j;
    int k;
    cin >> i >> j >> k;
    int result = beautifulDays(i, j, k);
    cout << result << endl;
    return 0;
}
