#include "stdlib.h"
#include "stdio.h"
#include "omp.h"

int main(){

/**
    omp_set_num_threads(4);
#pragma omp parallel
{
    int ID = omp_get_thread_num();
    printf( "hello(%d)", ID);
    printf( "world(%d)\n", ID);
}
*/

    int i;
    double x, sPi, ompPi, sum = 0.0, step;
    const static long num_steps = 100000;

    //Sequential vertion of pi
    double start = omp_get_wtime();
    step = 1.0 / (double) num_steps;

    for(i = 0; i < num_steps; i++){
        x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }

    sPi = step * sum;

    printf("Sequential pi: %0.10f in %f time\n", sPi, omp_get_wtime()-start);
    //end of sequential pi


    sum = 0.0;
    
    //OpenMP version of pi
    start = omp_get_wtime();
#pragma omp parallel num_threads(20)
    for(i = 0; i < num_steps; i++){
        x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }

    ompPi = step * sum;

    printf("OpenMP pi: %0.10f in %f time\n", ompPi, omp_get_wtime()-start);
    //end of OpenMP pi
    return 0;
}


