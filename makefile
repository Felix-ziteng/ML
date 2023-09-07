gcc 3d_test_enc.c -o ./../encrypt/parameters/3d_test_enc
gcc 3d_test_noenc.c -o ./../noencrypt/parameters/3d_test_noenc

gcc 3d10000sel_enc.c -o ../encrypt/parameters_learn/3d10000sel_enc
gcc 3d10000sel_noenc.c -o ../noencrypt/parameters_learn/3d10000sel_noenc

gcc 4d_test_enc.c -o ../encrypt/parameters/4d_test_enc
gcc 4d_test_noenc.c -o ../noencrypt/parameters/4d_test_noenc

gcc 4d10000sel_enc.c -o ../encrypt/parameters_learn/4d100000sel_enc
gcc 4d10000sel_noenc.c -o ../noencrypt/parameters_learn/4d100000sel_noenc

gcc 5d10000sel_enc.c -o ../encrypt/parameters_learn/5d10000sel_enc
gcc 5d10000sel_noenc.c -o ../noencrypt/parameters_learn/5d10000sel_noenc