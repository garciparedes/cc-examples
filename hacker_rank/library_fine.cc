#include <bits/stdc++.h>
#include <ctime>

using namespace std;

int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
    int result = 0;
    if (y1 == y2 && m1 >= m2) {
        if (m1 == m2 && d1 > d2) { 
            result = 15 * (d1 - d2);          
        } else if (m1 > m2){
            result = 500 * (m1 - m2);
        }
    } else if (y1 > y2) {
        result = 10000; 
    }
    return result;
}

int main() {
    int d1;
    int m1;
    int y1;
    cin >> d1 >> m1 >> y1;
    int d2;
    int m2;
    int y2;
    cin >> d2 >> m2 >> y2;
    int result = libraryFine(d1, m1, y1, d2, m2, y2);
    cout << result << endl;
    return 0;
}

