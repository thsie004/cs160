#include "stdlib.h"
#include "stdio.h"
#include "omp.h"

int main(int argc, char* argv[]){
    int i, n;

    //Checks for argument
    if(argc != 2){
        printf("Missing the number of threads as argument\n");
    }else if( !( n = atoi(argv[1]) ) ){
	printf("Invalid argument, please enter a valid number\n");
    }

    double x, sPi = 0, ompPi = 0, sum = 0.0, step;
    const static long num_steps = 100000;

    //Sequential vertion of pi
    double start = omp_get_wtime();
    step = 1.0 / (double) num_steps;

    for(i = 0; i < num_steps; i++){
        x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }

    sPi = step * sum;

    printf("Sequential pi is %0.10f calculated in %f seconds\n", sPi, omp_get_wtime()-start);
    //end of sequential pi

    //OpenMP version of pi
    start = omp_get_wtime();
    omp_set_num_threads(n);     
#pragma omp parallel
{
    int ID = omp_get_thread_num(), I;
    int start = (int) ((double) ID / (double) n * num_steps); 
    int end = (int) ((double) (ID+1) / (double) n * num_steps);
    double storage = 0.0, X;

    for(I = start; I < end; I++){
        X = (I + 0.5) * step;
        storage += 4.0 / (1.0 + X * X);
    }
#pragma omp atomic
    ompPi += storage;
}
    
    ompPi *= step;

    printf("OpenMP pi is %0.10f calculated in %f seconds.\n", ompPi, omp_get_wtime()-start);
    //end of OpenMP pi
    return 0;
}


