#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double distance_1(double x_1, double x_2, double y_1, double y_2) {
    return pow(acos(x_1 * y_1  + x_2 * y_2), 2.0);
}


double distance_vector_1(vector<double> theta_1, vector<double> theta_2) {
    if (theta_1.size() != theta_2.size()) {
        return - 1;
    }
    int i, n = theta_1.size();
    double d = 0.0;
    for (i = 0; i < n; i++) {
        d = d + distance_1(cos(theta_1[i]), sin(theta_1[i]),
                           cos(theta_2[i]), sin(theta_2[i]));
    }
    return d;
}


double distance_vector_1(vector<double> x_1, vector<double> x_2,
                         vector<double> y_1, vector<double> y_2 ) {
    if (x_1.size() != x_2.size() or x_1.size() != y_1.size() or
        x_1.size() != y_2.size()) {
        return - 1;
    }
    int i, n = x_1.size();
    double d = 0.0;
    for (i = 0; i < n; i++) {
        d = d + distance_1(x_1[i], x_2[i], y_1[i], y_2[i]);
    }
    return d;
}


int main() {
    vector<double> theta_1 = {1.0, 2.0, 3.0, 10000.0};
    vector<double> theta_2 = {1.0, 2.0, 3.0, 10000.0};

    cout << distance_vector_1(theta_1, theta_2) << endl;

    vector<double> x_1(theta_1.size());
    vector<double> x_2(theta_1.size());
    vector<double> y_1(theta_2.size());
    vector<double> y_2(theta_2.size());

    for(int i = 0; i < theta_1.size(); i++) {
        x_1[i] = cos(theta_1[i]);
        x_2[i] = sin(theta_1[i]);
        y_1[i] = cos(theta_2[i]);
        y_2[i] = sin(theta_2[i]);
    }
    cout << distance_vector_1(theta_1, theta_2) << endl;

    return 0;
}
