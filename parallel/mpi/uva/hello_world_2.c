#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {

    int rank, size, length;
    char name[BUFSIZ];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Get_processor_name(name, &length);


    printf("Hi, I'm %d of %d and I'm running on %s\n",rank,size, name);

    MPI_Finalize();
    return 0;
}
