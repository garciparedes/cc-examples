#include <bits/stdc++.h>
#include <string>
#include <regex>

using namespace std;


const string special_string = "!@#$%^&*()-+";

bool is_digit(char c) {
   return '0' <= c && c <= '9';
} 


bool is_lower(char c) {
   return 'a' <= c && c <= 'z';
} 


bool is_upper(char c) {
   return 'A' <= c && c <= 'Z';
} 

bool is_special(char c) {
    bool result = false;
    auto it = special_string.begin();
    while(it != special_string.end() && !result) {
        result = *it == c;
        ++it;
    }
    return result;
}

int minimum_number(int n, string p) {
    int result = 0;
    bool with_digit = false, 
         with_lower = false, 
         with_upper = false, 
         with_special = false;


    for (auto it = p.begin(); it != p.end(); ++it) {
    
        if (!with_digit) {
            with_digit = is_digit(*it);
        } 
        if (!with_lower) {
            with_lower = is_lower(*it);
        } 
        if (!with_upper) {
            with_upper = is_upper(*it);
        } 
        if (!with_special) {
            with_special = is_special(*it);
        } 

    }

    result =  4 - (with_digit + with_lower + with_upper + with_special);
    if (n < 6) {
        result = max(6 - n, result);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    string password;
    cin >> password;
    cout << minimum_number(n, password) << '\n';
    return 0;
}

