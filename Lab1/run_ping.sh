#!/bin/bash
mpicc -o hw homework2.c -std=gnu99
export MPIR_CVAR_CH3_NOLOCAL=0
mpiexec -np 4 --machinefile ./1node ./hw > 1nodeLocal_ping.out
export MPIR_CVAR_CH3_NOLOCAL=1
mpiexec -np 4 --machinefile ./1node ./hw > 1nodeNoLocal_ping.out
mpiexec -np 4 --machinefile ./2nodes1machine ./hw > 2nodes1machine_ping.out
mpiexec -np 4 --machinefile ./2nodes2machines ./hw > 2nodes2machines_ping.out

