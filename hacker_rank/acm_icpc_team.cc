#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int sum_wise(string a, string b) {
    int result = 0;
    for (int i = 0; i < a.size(); ++i) {
        result += a[i] == '1' || b[i] == '1';
    }
    return result;
}

vector <int> acmTeam(vector <string> topic) {
    vector<int> result(2);
    vector<int> values (topic.size() * (topic.size() - 1) / 2);
    int k = 0;
    for(int i = 0; i < topic.size(); ++i) {
        for(int j = i + 1; j < topic.size(); ++j) {
            values[k++] = sum_wise(topic[i], topic[j]);
        }
    }
    result[0] = *max_element(values.begin(), values.end());
    result[1] = count(values.begin(), values.end(), result[0]);
    return result;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<string> topic(n);
    for(int topic_i = 0; topic_i < n; topic_i++){
       cin >> topic[topic_i];
    }
    vector <int> result = acmTeam(topic);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
    return 0;
}

