#include <bits/stdc++.h>

using namespace std;

vector <int> climbingLeaderboard(vector <int> scores, vector <int> alice) {
    vector<int>::iterator alice_it;
    vector<int>::iterator result_it;
    vector<int>::iterator scores_it;
    vector<int> result(alice.size());
    scores.erase(unique(scores.begin(), scores.end()), scores.end() );
    scores_it = scores.end() - 1;
    result_it = result.begin();
    for (alice_it = alice.begin(); alice_it != alice.end(); ++alice_it) {
        while(*(alice_it) >= *(scores_it) && scores_it != scores.begin() - 1) {
            --scores_it;
        }
        *(result_it) = distance(scores.begin() - 1, scores_it + 1);
        ++result_it;
	}
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> scores(n);
    for(int scores_i = 0; scores_i < n; scores_i++){
       cin >> scores[scores_i];
    }
    int m;
    cin >> m;
    vector<int> alice(m);
    for(int alice_i = 0; alice_i < m; alice_i++){
       cin >> alice[alice_i];
    }
    vector <int> result = climbingLeaderboard(scores, alice);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
