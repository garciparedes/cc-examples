#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <regex>
#include <utility>

using namespace std;

string extract_data(string data, string tag_path, string attr) {
    stringstream pre_re;
    smatch match_results;
    string matched, token, delimiter;
    int pos, i, j;
    delimiter = ".";
    pre_re << "^.*";
    i = 1;
    pos = 0;
    while ((pos = tag_path.find(delimiter)) != string::npos) {
        token = tag_path.substr(0, pos);
        pre_re << "<(" << token << ")(?: [^>]*)?>.*";

        tag_path.erase(0, pos + delimiter.length());
        i++;
    }
    pre_re <<
        "<(" << tag_path <<")(?: [^>]*)?" <<
        " " << attr << " = \"([^\"]+)\"(?: [^>]*)?>.*";

    for(j = i; 1 <= j; j--) {
        pre_re << "</(\\" + to_string(j) + ")>";
    }
    pre_re << ".*$";

    // cout << pre_re.str() << endl;


    regex data_re(pre_re.str());
    if (regex_match(data, match_results, data_re)) {
        matched = match_results[i + 1].str();
    } else {
        matched = "Not Found!";
    }
    return matched;

}

string do_query(string data, string query) {
    string tag_path, attr;
    regex query_re( R"(([^\~]+)\~([^\~]+))");
    smatch match_results;

    if (regex_match(query, match_results, query_re)) {
        tag_path = match_results[1].str();
        attr = match_results[2].str();
    }

    return extract_data(data, tag_path, attr);
}



int main() {

    int N, Q, i;
    string data, temp_str;

    cin >> N >> Q >> ws;

    for(i = 0; i < N; i++) {
        getline(cin, temp_str);
        data = data + temp_str;
    }


    for(i = 0; i < Q; i++) {
        getline(cin, temp_str);
        cout << do_query(data, temp_str) << endl;
    }


    return 0;
}
