#!/bin/bash
cd /home/cristiano/Documents/pulp-sdk/tests/qsort/encrypt/parameters_learn/
./9d10000_enc

cd /home/cristiano/Documents/pulp-sdk/tests/qsort/noencrypt/parameters_learn/
./9d10000_noenc

cd /home/cristiano/Documents/pulp-sdk/tests/qsort/encrypt/parameters/
./9d_test_enc

cd /home/cristiano/Documents/pulp-sdk/tests/qsort/noencrypt/parameters/
./9d_test_noenc

cd /home/cristiano/Documents/pulp-sdk/tests/qsort/scripts/
python3 ml_malware.py

