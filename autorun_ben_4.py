import itertools
import subprocess
import time

# Define the list of file names
file_names = ["branch_cnt.txt", "btaken_cnt.txt", "clk_cnt.txt", "instr_cnt.txt", "jump_cnt.txt", "ld_cnt.txt", "ls_cnt.txt", "rcv_cnt.txt", "st_cnt.txt"]

# Define the paths
path_local = "/home/cristiano/Documents/pulp-sdk/tests/qsort/scripts/"
path_encrypt_learn = "/home/cristiano/Documents/pulp-sdk/tests/qsort/encrypt/parameters_learn/"
path_noencrypt_learn = "/home/cristiano/Documents/pulp-sdk/tests/qsort/noencrypt/parameters_learn/"
path_encrypt_test = "/home/cristiano/Documents/pulp-sdk/tests/qsort/encrypt/parameters/"
path_noencrypt_test = "/home/cristiano/Documents/pulp-sdk/tests/qsort/noencrypt/parameters/"
path_results = "/home/cristiano/Documents/pulp-sdk/tests/qsort/results_benign/"

# Open a log file to record the results
# with open("4_reg_machine_learning_benign_results.log", "w") as log_file:
with open(path_results + "4_reg_machine_learning_benign_results.log", "w") as log_file:
  
  # Loop through all quadruples of files
  for files_comb in itertools.combinations(file_names, 4):
      
      # Print the file names to the log
      files_comb_str = " ".join(files_comb)
      log_file.write(f"{files_comb_str}\n")
      
      # Run the first command : encrypt learn
      subprocess.check_call([path_encrypt_learn + "4d10000sel_enc"] + [path_encrypt_learn + f for f in files_comb])
      
      # Run the second command : noencrypt learn
      subprocess.check_call([path_noencrypt_learn + "4d10000sel_noenc"] + [path_noencrypt_learn + f for f in files_comb])
      
      # Run the third command : encrypt test
      subprocess.check_call([path_encrypt_test + "4d_test_enc"] + [path_encrypt_test + f for f in files_comb])

      # Run the fourth command : noencrypt test
      subprocess.check_call([path_noencrypt_test + "4d_test_noenc"] + [path_noencrypt_test + f for f in files_comb])
      
      # Print the results of the last command to the log
      result = subprocess.check_output(["python3", path_local + "ml_benign.py"])
    #   # Sleep for 0.5 seconds
    #   time.sleep(0.5)
      log_file.write(result.decode("utf-8"))
      log_file.write("\n")

      
