#include <bits/stdc++.h>

using namespace std;

int findDigits(int n) {
    int temp = n, digit = 0, count = 0;
    while(temp > 0) {
        digit = temp % 10;
        temp = temp / 10;
        count += (digit != 0 && n % digit == 0) ? 1 : 0;
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int result = findDigits(n);
        cout << result << endl;
    }
    return 0;
}
