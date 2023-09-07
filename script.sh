#!/bin/bash

rm qsort.log
while true; do
    make run >> qsort.log
    # wait for the simulation to finish
    sleep 1
    ./random
done
