#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    stringstream ss(str);
    char ch;
    int a;
    vector<int> result;
    if (ss) {
        ss >> a;
    }
    result.push_back(a);
    while(!ss.eof()){
        ss >> ch >> a;
        result.push_back(a);
    }
    return result;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
