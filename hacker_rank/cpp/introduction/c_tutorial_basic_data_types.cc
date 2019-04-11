#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int i;
  long l;
  char c;
  float f;
  double d;

  scanf("%i %li %c %f %lf", &i, &l, &c, &f, &d);
  printf("%i\n%li\n%c\n%f\n%lf\n", i, l, c, f, d);

  return 0;
}