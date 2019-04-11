#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int n;
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++) {
    scanf("%i", &arr[i]);
  }
  for (int i = n - 1; 0 <= i; i--) {
    printf("%i ", arr[i]);
  }

  return 0;
}
