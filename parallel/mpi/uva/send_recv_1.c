#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {

    int rank;
    int data = 0;
    int tag = 0;

    MPI_Status stat;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        data = 123;
    }

    printf("Process %d, data=%d\n", rank, data);

    if (rank == 0) {
        MPI_Send(&data, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
    } else {
        MPI_Recv(&data, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &stat);
    }

    printf("Process %d, data=%d\n", rank, data);

    MPI_Finalize();
    return 0;
}
