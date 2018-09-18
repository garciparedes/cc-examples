#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int diff(int a, int b) {
  return abs(b - a);
}

vector<int> closestNumbers(vector<int> arr) {
  sort(arr.begin(), arr.end());

  auto it = arr.begin();

  vector<int> result;
  result.push_back(*(it));
  result.push_back(*(it + 1));

  for (it += 1; it < arr.end() - 1; it += 1) {

    if (*(it) == *(it + 1)) {
      continue;
    }

    if (diff(result[0], result[1]) < diff(*(it), *(it + 1))) {
      continue;
    }

    if (diff(*(it), *(it + 1)) < diff(result[0], result[1])) {
      result.clear();
    }

    result.push_back(*(it));
    result.push_back(*(it + 1));
  }

  return result;
}

int main() {
  unsigned long n;
  cin >> n;

  vector<int> arr(n);

  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    arr[i] = temp;
  }

  vector<int> result = closestNumbers(arr);

  for (int value : result) {
    cout << value << ' ';
  }
  return 0;
}