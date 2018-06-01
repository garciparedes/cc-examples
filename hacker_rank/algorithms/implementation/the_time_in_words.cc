#include <bits/stdc++.h>

using namespace std;

const string time_oclock = "o' clock", time_past = "past", time_to = "to",
      time_minute = "minute", time_minutes = "minutes", time_quarter = "quarter",
      time_half = "half";

const string small_numbers[] = {
    "", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "fifteen",
    "sixteen", "seventeen", "eighteen", "nineteen"
};

const string tens[] = {
    "", "", "twenty", "thirty", "forty", 
    "fifty", "sixty", "seventy", "eighty", "ninety"
};  

string timeInWords(int h, int m) {
    stringstream ss;

    if (m == 0) {
        ss << small_numbers[h] << ' ' << time_oclock;
    } else if (m <= 30) {
        if (m == 15) {
            ss << time_quarter;
        } else if (m == 30) {
             ss << time_half;
        } else {
            if (m < 20) {
                ss << small_numbers[m];
            } else {
                ss << tens[m / 10] <<  (m % 10 == 0 ? "" : ' ' + small_numbers[m % 10]);
            }
            if (m == 1) {
                ss << ' ' << time_minute;
            } else {
                ss << ' ' << time_minutes;
            }
        }
        ss << ' ' << time_past << ' ' << small_numbers[h]; 
    } else {
        if (m == 45) {
            ss << time_quarter;
        } else {
            if (m > 40) {
                ss << small_numbers[60 - m];
            } else {
                ss << tens[(60 - m) / 10]  << (m % 10 == 0 ? "" : ' ' + small_numbers[(60 - m) % 10]);
            }
            if (m == 1) {
                ss << ' ' << time_minute;
            } else {
                ss << ' ' << time_minutes;
            }
        }
        ss << ' ' << time_to <<  ' ' << small_numbers[(h + 1) % 12]; 
    }
    return ss.str();
}

int main() {
    int h;
    cin >> h;
    int m;
    cin >> m;
    string result = timeInWords(h, m);
    cout << result << endl;
    return 0;
}

