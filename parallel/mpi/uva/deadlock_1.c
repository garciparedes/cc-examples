#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {

    int rank, size; int data;
    int tag = 0;
    MPI_Init( &argc, &argv );
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );

    int dest = (rank +1 ) % size;
    int source = (rank -1 + size) % size;

    MPI_Request request;

    MPI_Irecv(&data, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &request);
    data = 123;
    MPI_Send(&data, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
    MPI_Wait(&request, MPI_STATUS_IGNORE);

    MPI_Finalize();
    return 0;
}
