//
// Created by albert on 07.03.19.
//

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int main(int argc, char* argv[])
{
  for(int i=0;i<argc;i++)
  printf("%s\n",argv[i]);
  printf("%d\n",atoi(argv[1]));

    int kolo=0;
    int kwadrat=atoi(argv[1]);
    //printf("%d\n",kwadrat);
    double x,y;
    Init(argv);
    //MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);\
    srand(time(NULL));
    //printf("aaaaa\n");
    MPI_Barrier(MPI_COMM_WORLD);
    //printf("asdf\n");
    double time = MPI_Wtime();
    for(int i=1;i<kwadrat;i++)
    {
      //printf("%d %d %d\n",kwadrat, world_rank, world_size);
        x=y=5;
        while(x>1)
        {
          //printf("asdfasdf\n");
          x=rand()/2000000000.0;
        }
        while(y>1)
        {
          //printf("asdfasdf2\n");
          y=rand()/2000000000.0;
        }
        //time = mpi_send_test(i*1000000);

        //    printf("process 0 has ended sending %d bytes after %f seconds\n",i,time);
        //MPI_Barrier(MPI_COMM_WORLD);
        if(x*x+y*y<=1)
          kolo++;
        //kwadrat++;


    }
    long long l;
    int buffer1 = kolo;
    int buffer2 = 0;

    MPI_Reduce(&buffer1,&buffer2, 1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
    //printf("bbbbb\n");
    int kwadratll = kwadrat*world_size;
    double pi = 4.0 * buffer2 / kwadratll;
    double time2 = MPI_Wtime();
    //printf("%d\n",world_rank);
    if(world_rank==0)
        printf("%f %f %d\n",pi,time2-time, kwadratll);
    Finalize();
}
