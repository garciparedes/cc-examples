#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define MENSSAGE_COUNT	10
#define RANK_SENDER	0
#define RANK_RECEIVER	1


int main(int argc, char *argv[]) {

    int world_rank, world_size;

    int tag = 0;

    int i, j;
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

        for (j = 0; j < world_size; j++) {
            if(j != RANK_SENDER){
                printf("Sending to %d...\n",j);
                for (i = 0; i < MENSSAGE_COUNT; i++)
                {
                    MPI_Rsend(&data[i], 1, MPI_INT, j, tag, MPI_COMM_WORLD);
                }
                printf("Sent to %d!\n", j);
            }
        }
    } else{
        printf("Receiving on %d...\n", world_rank);
        for (i = 0; i < MENSSAGE_COUNT; i++) {
            MPI_Recv(&data[i], 1, MPI_INT, RANK_SENDER, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        printf("Received on %d!\n", world_rank);

        for (i = 0; i < MENSSAGE_COUNT; i++) {
            printf("%c  ", data[i]);
        }
        printf("\n");
    }


    MPI_Finalize();
    return 0;
}
