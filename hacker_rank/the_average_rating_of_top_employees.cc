#include <bits/stdc++.h>

using namespace std;

// Complete the averageOfTopEmployees function below.
float averageOfTopEmployees(vector<int> rating) {
    float s = 0;
    int n = 0;

    for(auto it = rating.begin(); it != rating.end(); ++it) {
        if (*it >= 90) {
            s += *it;
            ++n;
        }
    }
    return round((s / n) * 100) / 100 ;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> rating(n);

    for (int rating_itr = 0; rating_itr < n; rating_itr++) {
        int rating_item;
        cin >> rating_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        rating[rating_itr] = rating_item;
    }

    cout
        << fixed
        << setprecision(2)
        << averageOfTopEmployees(rating)
        << '\n';;

    return 0;
}
