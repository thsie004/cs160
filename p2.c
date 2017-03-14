/**Problem 2 for homework 4 for CS160
 * Tung Lin Hsieh
 * thsie004@ucr.edu
 */
#include "stdlib.h"
#include "stdio.h"
#include "omp.h"

int main(int argc, char* argv[]){
    int i, n;

    //Checks for argument
    if(argc != 2){
        printf("Missing the number of threads as argument\n");
        return -1;
    }else if( !( n = atoi(argv[1]) ) ){
	    printf("Invalid argument, please enter a valid number\n");
        return -1;
    }

    const static long num_steps = 100000;
    double x, sPi = 0, start, ompPi = 0.0, sum = 0.0, step = 1.0 / (double) num_steps;

    //Sequential vertion of pi
    start = omp_get_wtime();

    for(i = 0; i < num_steps; i++){
        x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }

    sPi = step * sum;

    printf("Sequential pi is %0.20f calculated in %f seconds\n", 
            sPi, omp_get_wtime()-start);
    //end of sequential pi

    //OpenMP version of pi
    start = omp_get_wtime();
    omp_set_num_threads(n);
    
    #pragma omp parallel for private(x) reduction(+:ompPi) 
    for(i = 0; i < num_steps; i++){
        x = (i + 0.5) * step;
        ompPi += 4.0 / (1.0 + x * x);
    }

    ompPi *= step;

    printf("    OpenMP pi is %0.20f calculated in %f seconds.\n", 
            ompPi, omp_get_wtime()-start);
    //end of OpenMP pi
    
    return 0;
}


