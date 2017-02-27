# !/bin/bash


ulimit -s 65532

g++-6  -fopenmp "$@"

export OMP_NUM_THREADS=1
echo "Threads: $OMP_NUM_THREADS"
time ./a.out

export OMP_NUM_THREADS=64
echo "Threads: $OMP_NUM_THREADS"
time ./a.out

rm a.out
