//
// Created by albert on 07.03.19.
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

double ping() {
    MPI_Barrier(MPI_COMM_WORLD);
    double start,end;
    int numbers = 0;
    start = MPI_Wtime();
    if (world_rank == 0) {
        // If we are rank 0, set the number to -1 and send it to process 1

        MPI_Send(&numbers, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&numbers, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    } else if (world_rank == 1) {
        MPI_Recv(&numbers, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Send(&numbers, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        //printf("Process 1 received number %d from process 0\n", number);
    }
    end = MPI_Wtime();
    return end-start;
}
int main(int argc, char* argv[])
{
    int provided;
    Init(argv);
    //MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);
    double time;
    double summed_ping = 0;
    for(int i=1;i<1000;i++)
    {
        time = ping();
        //if(world_rank==0)
        //    printf("process 0 has ended sending %d bytes after %f seconds\n",i,time);
        //MPI_Barrier(MPI_COMM_WORLD);

        //if(world_rank==0)
          //  printf("%f\n",time);
        summed_ping += time;
    }
    if(world_rank==0)
      printf("%f\n",summed_ping/1000.0);
    Finalize();
}
