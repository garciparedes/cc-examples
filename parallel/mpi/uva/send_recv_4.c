#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {

    int rank, size, i;

    int data = 0;
    int tag = 0;

    int loops = 1;

    MPI_Status stat;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(argc > 1){
        loops = atoi(argv[1]);
    }

    for(i = 0; i < loops; i++){
        if (rank == 0) {
            data++;
            MPI_Send(&data, 1, MPI_INT, (rank+1+size) % size, tag, MPI_COMM_WORLD);
            data = 0;
            MPI_Recv(&data, 1, MPI_INT, (rank-1+size) % size, tag, MPI_COMM_WORLD, &stat);
            printf("data=%d\n", data);

        } else {
            MPI_Recv(&data, 1, MPI_INT, (rank-1+size) % size, tag, MPI_COMM_WORLD, &stat);
            MPI_Send(&data, 1, MPI_INT, (rank+1+size) % size, tag, MPI_COMM_WORLD);
            data = 0;
        }
    }

    MPI_Finalize();
    return 0;
}
