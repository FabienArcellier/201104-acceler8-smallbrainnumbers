#!/bin/sh

export OMP_NUM_THREADS=40
export LD_LIBRARY_PATH=/opt/intel/Compiler/latest/lib/intel64:$LD_LIBRARY_PATH
/home/rimaxime/repository/build/Smallbrain 1 9223372036854775807
