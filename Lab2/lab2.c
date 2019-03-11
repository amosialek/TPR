//
// Created by albert on 11.03.19.
//


#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int world_rank;
int world_size;
void Init(char * argv[])
{
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    if (world_size < 2) {
        fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
}
void Finalize()
{
    MPI_Finalize();
}

void broadcast()
{
    char* buffer = malloc(7*sizeof(char));
    char* buffer2 = malloc(7*sizeof(char));
    buffer[0]='t';
    buffer[1]='p';
    buffer[2]='r';
    buffer[3]='2';
    buffer[4]='0';
    buffer[5]='1';
    buffer[6]='9';


    if(world_rank == 0)
        MPI_Bcast(buffer,7,MPI_CHAR,0,MPI_COMM_WORLD);
    else
        MPI_Bcast(buffer2,7,MPI_CHAR,0,MPI_COMM_WORLD);
    if(world_rank == 1) {

        for (int i = 0; i < 7; i++)
            printf("%c", buffer2[i]);
        printf("\n");
    }
    MPI_Barrier(MPI_COMM_WORLD);

    if(world_rank == 2) {

        for (int i = 0; i < 7; i++)
            printf("%c", buffer2[i]);
        printf("\n");
    }

    free(buffer);
    free(buffer2);

}

void gather()
{


}

void scatter()
{


}

void reduce()
{


}


int main(int argc, char* argv[])
{
    Init(argv);
broadcast();
    MPI_Finalize();

    return 0;
}