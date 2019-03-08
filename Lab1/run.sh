#!/bin/bash
mpicc -o hw homework1.c
export MPIR_CVAR_CH3_NOLOCAL=0
mpiexec -np 4 ./hw --machinefile 1node > 1nodeLocal.out
export MPIR_CVAR_CH3_NOLOCAL=1
mpiexec -np 4 ./hw --machinefile 1node > 1nodeNoLocal.out
mpiexec -np 4 ./hw --machinefile 2nodes1machine > 2nodes1machine.out
mpiexec -np 4 ./hw --machinefile 2nodes2machines > 2nodes2machines.out

