#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main() {

	omp_set_num_threads(4);
   int a = 1;
   #pragma omp parallel reduction(*:a)
   {
      a = 2;
      #pragma omp sections
	  {
		  #pragma omp section
		  a = 1;
		  #pragma omp section
		  a = 3;
	  }
   }
   printf("%d", a);

	return 0;
}
