#!/bin/bash

mkdir -p ../scripts
gcc 2d_test_enc.c -o ./../encrypt/parameters/2d_test_enc
gcc 2d_test_noenc.c -o ./../noencrypt/parameters/2d_test_noenc

gcc 2d10000sel_enc.c -o ../encrypt/parameters_learn/2d10000sel_enc
gcc 2d10000sel_noenc.c -o ../noencrypt/parameters_learn/2d10000sel_noenc

gcc 3d_test_enc.c -o ./../encrypt/parameters/3d_test_enc
gcc 3d_test_noenc.c -o ./../noencrypt/parameters/3d_test_noenc

gcc 3d10000sel_enc.c -o ../encrypt/parameters_learn/3d10000sel_enc
gcc 3d10000sel_noenc.c -o ../noencrypt/parameters_learn/3d10000sel_noenc

gcc 4d_test_enc.c -o ../encrypt/parameters/4d_test_enc
gcc 4d_test_noenc.c -o ../noencrypt/parameters/4d_test_noenc

gcc 4d10000sel_enc.c -o ../encrypt/parameters_learn/4d100000sel_enc
gcc 4d10000sel_noenc.c -o ../noencrypt/parameters_learn/4d100000sel_noenc\

gcc 5d_test_enc.c -o ../encrypt/parameters/5d_test_enc
gcc 5d_test_noenc.c -o ../noencrypt/parameters/5d_test_noenc

gcc 5d10000sel_enc.c -o ../encrypt/parameters_learn/5d10000sel_enc
gcc 5d10000sel_noenc.c -o ../noencrypt/parameters_learn/5d10000sel_noenc

gcc 9d_test_enc.c -o ../encrypt/parameters/9d_test_enc
gcc 9d_test_noenc.c -o ../noencrypt/parameters/9d_test_noenc

gcc 9d10000_enc.c -o ../encrypt/parameters_learn/9d10000_enc
gcc 9d10000_noenc.c -o ../noencrypt/parameters_learn/9d10000_noenc

cp ml_malware.py ../scripts/.
cp ml_benign.py ../scripts/.
cp autorun_mal_2.py ../scripts/.
cp autorun_mal_3.py ../scripts/.
cp autorun_mal_4.py ../scripts/.
cp autorun_mal_5.py ../scripts/.
cp autorun_ben_2.py ../scripts/.
cp autorun_ben_3.py ../scripts/.
cp autorun_ben_4.py ../scripts/.
cp autorun_ben_5.py ../scripts/.
cp allben_9.sh ../scripts/.
cp allmal_9.sh ../scripts/.
cp readall ../encrypt/
cp readall ../noencrypt/

chmod +x ../encrypt/readall
chmod +x ../noencrypt/readall
chmod +x ../scripts/allben_9.sh
chmod +x ../scripts/allmal_9.sh




printf "Done compiling all files\n"