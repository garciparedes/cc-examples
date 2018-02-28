#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

#define SIZE	200000000
int main() {
	double time = omp_get_wtime();

	int threads_num = omp_get_max_threads();

    int *v = (int *)malloc( SIZE * sizeof(int) );
    int *partial_sum = (int *)malloc(threads_num * sizeof(int) );

	int i;
	int sum = 0;

	#pragma omp parallel for shared( partial_sum ), private( i )
	for ( i=0; i<threads_num; i++ ) partial_sum[i] = 0;

	#pragma omp parallel for shared( v ), private( i )
	for ( i=0; i<SIZE; i++ ) v[i] = i;

	#pragma omp parallel for shared( v, partial_sum ), private( i )
	for ( i=0; i<SIZE; i++ )
		partial_sum[omp_get_thread_num()] = ( partial_sum[omp_get_thread_num()] + v[i] ) % 65535;

	for ( i=0; i<threads_num; i++ )
		sum = ( sum + partial_sum[i] ) % 65535;

	printf( "Time: %lf\n", omp_get_wtime() - time);
	printf( "Final Result: %d\n", sum );

	return 0;
}
