#!/bin/bash

#Produces records of p1, p2, p3 running with n=1-8 threads

make all

for (( i = 1; i <= 3; i++));
do
    echo "===PROBLEM $i===" >> rec

    for (( n = 1; n <= 8; n++));
    do
        echo "  n = $n: " >> rec
        ./p$i $n >> rec
        echo "    ---    " >> rec
    done

    echo "===============" >> rec

done
