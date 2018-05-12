#include <bits/stdc++.h>

using namespace std;


int which_number(vector<int> scores) {
    size_t size = scores.size();
    unsigned long long total = 0, cum = 0;
    int i, i_saved;
    for(i = 0; i < size; i++) {
        total += scores[i];
    }
    i = 0, i_saved = 0;

    for(i = 1; i < size; i++) {
        if (scores[i_saved] < scores[i]) {
            i_saved = i;
        }
    }
    return i_saved;

}



// Complete the maximumSuperiorCharacters function below.
unsigned long long maximum_superior_characters(vector<int> freq) {
    unsigned long long result = 0, a = 0, total = 0;
    int i, m;

    vector<int> arr;
    vector<int>::iterator it1;
    vector<int>::iterator it2;

    for (i = 0; i < freq.size(); i++){
        if(freq[i] != 0) {
            arr.push_back(freq[i]);
            total += freq[i];
        }
    }

    //which_number(arr);
    if (arr.size() > 1) {

        // for (auto i : arr) {
        //     cout << i << ' ';
        // }
        // cout << '\n';

        total = 0;
        for(int j = 0; j < arr.size(); j++) {
            total += arr[j];
        }

        i = 0;
        a = arr[i];
        while(a + arr[i + 1] <= total / 2) {
            i += 1;
            a += arr[i];
        }
        if (a * 2 > total){
            arr[i] -= 1;
        } else if (arr[i] < arr[i + 1]){
            i+= 1;
            arr[i] -= 1;
        } else {
            arr[i + 1] -= 1;
        }

        // MEDIAN OF DATA
        it1 = arr.begin() + i;
        it2 = arr.end() - 1;

        //cout << distance(arr.begin(), it1) << '\t' << distance(arr.begin(), it2) << '\n';
        while(it1 >= arr.begin() && *it2 > 0 && it2 > it1 && *it1 != 0) {

            while(*it1 > 0 && it2 > it1 && *it2 > 0) {
                m = min(*it1, *it2);
                *it1 -= m;
                *it2 -= m;
                result += m;
                while (*it2 == 0 && it2 > arr.begin()) {
                    it2--;
                }
            }

            total = 0;
            for(int j = 0; j < arr.size(); j++) {
                total += arr[j];
            }

            i = 0;
            a = arr[i];
            while(a + arr[i + 1] <= total / 2 && arr[i + 1] > 0) {
                i += 1;
                a += arr[i];
            }

            // MEDIAN OF DATA
            it1 = arr.begin() + i;
        }

    }
    // for (auto i : arr) {
    //     cout << i << ' ';
    // }
    // cout << '\n';
    // cout << "\n\n\n";
    return result;
}

int main() {
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<int> freq(26);
    int freq_item;
    for (int t_itr = 0; t_itr < t; t_itr++) {
        for (int freq_itr = 0; freq_itr < 26; freq_itr++) {
            cin >> freq_item;
            freq[freq_itr] = freq_item;
        }
        unsigned long long result = maximum_superior_characters(freq);
        cout << result << '\n';
    }
    return 0;
}
