#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_the_median(vector<int> &numbers) {
  sort(numbers.begin(), numbers.end());
  unsigned long mid_index = numbers.size() / 2;
  return numbers[mid_index];
}

int main() {
  unsigned long cases;

  cin >> cases;

  vector<int> numbers(cases);
  int num;
  for (int i = 0; i < cases; i += 1) {
    cin >> num;
    numbers[i] = num;
  }
  cout << find_the_median(numbers) << '\n';


  return 0;
}