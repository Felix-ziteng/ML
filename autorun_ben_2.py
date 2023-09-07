import subprocess

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
# with open("2_reg_machine_learning_benign_results.log", "w") as log_file:
with open(path_results + "2_reg_machine_learning_benign_results.log", "w") as log_file:
  
  # Loop through all pairs of files
  for i in range(len(file_names)):
    for j in range(i+1, len(file_names)):
      
      # Print the file names to the log
      log_file.write(f"{file_names[i]} {file_names[j]}\n")
      
      # Run the first command : encrypt learn
      subprocess.check_call([path_encrypt_learn + "2d10000sel_enc", path_encrypt_learn + file_names[i], path_encrypt_learn + file_names[j]])
      
      # Run the second command : noencript learn
      subprocess.check_call([path_noencrypt_learn + "2d10000sel_noenc", path_noencrypt_learn + file_names[i], path_noencrypt_learn + file_names[j]])
      
      # Run the third command : encrypt test
      subprocess.check_call([path_encrypt_test + "2d_test_enc", path_encrypt_test + file_names[i], path_encrypt_test + file_names[j]])

      # Run the next command
      subprocess.check_call([path_noencrypt_test + "2d_test_noenc", path_noencrypt_test + file_names[i], path_noencrypt_test + file_names[j]])
      
      # Print the results of the last command to the log
      result = subprocess.check_output(["python3", path_local + "ml_benign.py"])
      log_file.write(result.decode("utf-8"))
      log_file.write("\n")
