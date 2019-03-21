//
// Created by albert on 07.03.19.
//

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

int world_rank;
int world_size;

void Init(char * argv[])
{
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//    if (world_size < 2) {
//        fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
//        MPI_Abort(MPI_COMM_WORLD, 1);
//    }
}

void Finalize()
{
    MPI_Finalize();
}

int64_t get_problem_size(int argc, char*argv[])
{
    if (argc==2) return atol(argv[1]);
    if (argc==3) return atol(argv[1])/world_size;
    return 1;
}

int main(int argc, char* argv[])
{
    Init(argv);
    int64_t problem_size = get_problem_size(argc, argv);
    int64_t kolo=0;
    int64_t kwadrat=problem_size;
    double x,y;
    srand(time(NULL));
    MPI_Barrier(MPI_COMM_WORLD);

    double time = MPI_Wtime();
    for(int64_t i=1;i<kwadrat;i++)
    {
        x=y=5;
        while(x>1)
        {
          x=1.0*rand()/RAND_MAX;
        }
        while(y>1)
        {
          y=1.0*rand()/RAND_MAX;
        }
        if(x*x+y*y<=1)
          kolo++;
    }
    int64_t l;
    int64_t buffer1 = kolo;
    int64_t buffer2 = 0;

    MPI_Reduce(&buffer1, &buffer2, 1, MPI_INT64_T, MPI_SUM,0,MPI_COMM_WORLD);
    int64_t kwadratll = kwadrat*world_size;
    double pi = 4.0 * buffer2 / kwadratll;
    double time2 = MPI_Wtime();
    if(world_rank==0)
        printf("%f %f %ld\n",pi,time2-time, kwadratll);
    Finalize();
}
