#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define MENSSAGE_COUNT	10
#define RANK_SENDER	0
#define RANK_RECEIVER	1


int main(int argc, char *argv[]) {

    int world_rank, world_size;

    int tag = 0;

    int i;
    char *data = (char *)malloc( MENSSAGE_COUNT * sizeof(char) );

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    for (i = 0; i < MENSSAGE_COUNT; i++) {
        data[i] = '_';
    }

    if (world_rank == RANK_SENDER) {
        for (i = 0; i < MENSSAGE_COUNT; i++) {
            data[i] = 'a'  + i;
        }

        printf("Sending...\n");
    	for (i = 0; i < MENSSAGE_COUNT; i++)
    	{
    		MPI_Rsend(&data[i], 1, MPI_INT, RANK_RECEIVER, tag, MPI_COMM_WORLD);
    	}
        printf("Sent!\n");
    } else if(world_rank == RANK_RECEIVER){

        printf("Receiving...\n");
        for (i = 0; i < MENSSAGE_COUNT; i++) {
            MPI_Recv(&data[i], 1, MPI_INT, RANK_SENDER, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        printf("Received!\n");

        for (i = 0; i < MENSSAGE_COUNT; i++) {
            printf("%c  ", data[i]);
        }
        printf("\n");

    }


    MPI_Finalize();
    return 0;
}
