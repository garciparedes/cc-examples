#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main() {

	omp_set_num_threads(4);
   int i;
   int a = 0;
   int b = 5;
   #pragma omp parallel for firstprivate(a) lastprivate(b)
   for (i=0; i<4; i++) {
       b = a + 1;
	   a = b;
   }
   printf("%d %d", a, b);

	return 0;
}
