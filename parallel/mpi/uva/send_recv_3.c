#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]) {

    int rank, size, i;
    int *data = NULL;
    int tag = 0;
    MPI_Status stat;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    data = (int *)malloc( size * sizeof(int) );

    for(i = 0; i < size; i++){
        data[i] = 0;
    }

    data[rank] = rank + 1;


    printf("P %d: First\n", rank);
    for(i = 0; i < size; i++){
        printf("\tdata[%d] = %d\n", i, data[i]);
    }
    printf("\n");

    for(i = 0; i < size; i++){
        if (i != rank){
            MPI_Send(&data[rank], 1, MPI_INT, i, tag, MPI_COMM_WORLD);
        }
    }

    for(i = 0; i < size; i++){
        if (i != rank){
            MPI_Recv(&data[i], 1, MPI_INT, i, tag, MPI_COMM_WORLD, &stat);
        }
    }

    printf("P %d: Last\n", rank);
    for(i = 0; i < size; i++){
        printf("\tdata[%d] = %d\n", i, data[i]);
    }
    printf("\n");

    MPI_Finalize();
    return 0;
}
