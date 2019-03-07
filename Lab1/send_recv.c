#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

void mpi_send_test(int argc, char** argv)
{
MPI_Init(NULL, NULL);
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  MPI_Barrier(MPI_COMM_WORLD);
  if(world_rank==1)
    for(int i=0;i<10000;i++)
    {
    printf("%s"," ");
    }
  // We are assuming at least 2 processes for this task
  if (world_size < 2) {
    fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }
  int number;
  if (world_rank == 0) {
    // If we are rank 0, set the number to -1 and send it to process 1
    number = -1;
    MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    MPI_Send(&number, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
    MPI_Send(&number, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
  } else if (world_rank == 1) {
    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process 1 received number %d from process 0\n", number);
  }
  else if (world_rank == 2) {
    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process 2 received number %d from process 0\n", number);
    }
    else if (world_rank == 3) {
    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process 3 received number %d from process 0\n", number);
    }
  MPI_Finalize();


}


void mpi_ssend_test(int argc, char** argv)
{
  MPI_Init(NULL, NULL);
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  MPI_Barrier(MPI_COMM_WORLD);
 if(world_rank==1)
    for(int i=0;i<10000;i++)
    {
    printf("%s"," ");
    }
  // We are assuming at least 2 processes for this task
  if (world_size < 2) {
    fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }
  int number;
  if (world_rank == 0) {
    // If we are rank 0, set the number to -1 and send it to process 1
    number = -1;
    MPI_Ssend(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    MPI_Ssend(&number, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
    MPI_Ssend(&number, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
  } else if (world_rank == 1) {
    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process 1 received number %d from process 0\n", number);
  }
  else if (world_rank == 2) {
    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process 2 received number %d from process 0\n", number);
    }
    else if (world_rank == 3) {
    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process 3 received number %d from process 0\n", number);
    }
  MPI_Finalize();


}

void mpi_bsend_test(int argc, char** argv)
{
MPI_Init(NULL, NULL);
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  MPI_Barrier(MPI_COMM_WORLD);

  // We are assuming at least 2 processes for this task
  if (world_size < 2) {
    fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  int *b = malloc(100000);
  int number;
  if (world_rank == 0) {
    // If we are rank 0, set the number to -1 and send it to process 1
    number = -1;
    MPI_Buffer_attach(b,4+MPI_BSEND_OVERHEAD);
    MPI_Bsend(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    MPI_Bsend(&number, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
    MPI_Bsend(&number, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
  } else if (world_rank == 1) {
    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process 1 received number %d from process 0\n", number);
  }
  else if (world_rank == 2) {
    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process 2 received number %d from process 0\n", number);
    }
    else if (world_rank == 3) {
    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process 3 received number %d from process 0\n", number);
    }
  MPI_Finalize();
   free(b);


}

void mpi_rsend_test(int argc, char** argv)
{
MPI_Init(NULL, NULL);
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  MPI_Barrier(MPI_COMM_WORLD);

  // We are assuming at least 2 processes for this task
  if (world_size < 2) {
    fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }
  int number;
  MPI_Request request;
  MPI_Status status;
  if (world_rank == 0) {
    //MPI_Barrier(MPI_COMM_WORLD);
    // If we are rank 0, set the number to -1 and send it to process 1
    number = -1;
    MPI_Rsend(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    MPI_Rsend(&number, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
    MPI_Rsend(&number, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
  } else if (world_rank == 1) {
    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    //MPI_Barrier(MPI_COMM_WORLD);
    //MPI_Wait(&request,&status);
    printf("Process 1 received number %d from process 0\n", number);
  }
  else if (world_rank == 2) {
    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    //MPI_Barrier(MPI_COMM_WORLD);
    //MPI_Wait(&request,&status);
    printf("Process 2 received number %d from process 0\n", number);
    }
    else if (world_rank == 3) {
    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    //MPI_Barrier(MPI_COMM_WORLD);
    //MPI_Wait(&request,&status);
    printf("Process 3 received number %d from process 0\n", number);
    }
  MPI_Finalize();


}

void mpi_isend_test(int argc, char** argv)
{
  MPI_Request request;
  MPI_Status status;
MPI_Init(NULL, NULL);
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  MPI_Barrier(MPI_COMM_WORLD);
  if(world_rank==1)
    for(int i=0;i<10000;i++)
    {
    //printf("%s"," ");
    }
  // We are assuming at least 2 processes for this task
  if (world_size < 2) {
    fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }
  int number;
  if (world_rank == 0) {
    // If we are rank 0, set the number to -1 and send it to process 1
    number = -1;
    MPI_Isend(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD,&request);
    MPI_Isend(&number, 1, MPI_INT, 2, 0, MPI_COMM_WORLD,&request);
    MPI_Isend(&number, 1, MPI_INT, 3, 0, MPI_COMM_WORLD,&request);
  } else if (world_rank == 1) {
    MPI_Irecv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &request);
    MPI_Wait(&request,&status);
    printf("Process 1 received number %d from process 0\n", number);
  }
  else if (world_rank == 2) {
    MPI_Irecv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &request);
    MPI_Wait(&request,&status);
    printf("Process 2 received number %d from process 0\n", number);
    }
    else if (world_rank == 3) {
    MPI_Irecv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &request);
    MPI_Wait(&request,&status);
    printf("Process 3 received number %d from process 0\n", number);
    }
  MPI_Finalize();


}



int main(int argc, char** argv) {
    mpi_isend_test(argc, argv);

  return 0;
}
