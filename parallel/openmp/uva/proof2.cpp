#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main() {

	omp_set_num_threads(4);
    int i, v[4];
    int a = 2;

    #pragma omp parallel for 
    for (i=0; i<4; i++) v[i] = i;

    #pragma omp parallel for
    for (i=0; i<4; i++) {
       v[i] = a + v[i];
       a = a + 1;
    }

    for (i=0; i<4; i++) 
        printf("%d ", v[i]);


	return 0;
}
