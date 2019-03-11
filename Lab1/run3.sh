#!/bin/bash
mpicc -o hw homework1.c -std=gnu99
export MPIR_CVAR_CH3_NOLOCAL=0
mpiexec -np 4 --machinefile ./1node ./hw > 1nodeLocal.out
export MPIR_CVAR_CH3_NOLOCAL=1
mpiexec -np 4 --machinefile ./1node ./hw > 1nodeNoLocal.out
mpiexec -np 4 --machinefile ./2nodes1machine ./hw > 2nodes1machine.out
mpiexec -np 4 --machinefile ./2nodes2machines ./hw > 2nodes2machines.out

