
#include<stdio.h>
#include<stdlib.h>
#include <math.h>

#include<omp.h>
#include <float.h>


#define SIZE	1024
#define SEED	6834723

int main() {
	int i,j,k;
	double suma = 0.0;
	
	double A[ SIZE ][ SIZE ];
	double B[ SIZE ][ SIZE ];
	double C[ SIZE ][ SIZE ];
	
	
	srand48( SEED );
	for (i=0; i<SIZE; i++) {
		for (j=0; j<SIZE; j++) {
			A[i][j] = drand48();
			B[i][j] = drand48();
		}
	}
 

	#pragma parallel for shared(A,B, C) private(i,j, k)
	for (i=0; i<SIZE; i++) {
		for (k=0; k<SIZE; k++) {
			double temp = 0.0;
			for (j=0; j<SIZE; j++) {
				temp +=  A[i][k] * B[k][j];
			}
			C[i][j] = temp;
		}
	}
	
	#pragma omp parallel for shared(A, B, C) private(i, j), reduction(+:suma) 
		for ( i=0; i<SIZE; i++ ) 
			for ( j=0; j<SIZE; j++ ) 
				suma = fmod(suma + *C[i,j], DBL_MAX) ;					
											
	printf("Results: %lf\n", suma);
	return 0;

}
