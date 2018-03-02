#include <iostream>
#include <string>
using namespace std;

int main() {

    string a, b;

    cin >> a;
    cin >> b;

    cout <<
        a.size() <<
        " " <<
        b.size() <<
        endl <<
        a + b <<
        endl <<
        b[0] + a.substr(1) <<
        " " <<
        a[0] + b.substr(1) <<
        endl;

    return 0;
}
