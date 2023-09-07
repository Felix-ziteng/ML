#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *filenames[] = {"/home/cristiano/Documents/pulp-sdk/tests/qsort/results_benign/2_reg_machine_learning_benign_results.log",
                         "/home/cristiano/Documents/pulp-sdk/tests/qsort/results_benign/3_reg_machine_learning_benign_results.log",
                         "/home/cristiano/Documents/pulp-sdk/tests/qsort/results_benign/4_reg_machine_learning_benign_results.log",
                         "/home/cristiano/Documents/pulp-sdk/tests/qsort/results_benign/5_reg_machine_learning_benign_results.log"};
    char *output_filenames[] = {"/home/cristiano/Documents/pulp-sdk/tests/qsort/results_benign/results_values/2_reg_machine_learning_benign_results.txt",
                                "/home/cristiano/Documents/pulp-sdk/tests/qsort/results_benign/results_values/3_reg_machine_learning_benign_results.txt",
                                "/home/cristiano/Documents/pulp-sdk/tests/qsort/results_benign/results_values/4_reg_machine_learning_benign_results.txt",
                                "/home/cristiano/Documents/pulp-sdk/tests/qsort/results_benign/results_values/5_reg_machine_learning_benign_results.txt"};
    char buffer[1024];
    char *result;
    FILE *fp, *out_fp;
    float accuracy, percentage;
    int i;

    for (i = 0; i < 4; i++) {
        fp = fopen(filenames[i], "r");
        if (fp == NULL) {
            printf("Error: Failed to open file %s\n", filenames[i]);
            return 1;
        }
        
        out_fp = fopen(output_filenames[i], "w");
        if (out_fp == NULL) {
            printf("Error: Failed to open file %s\n", output_filenames[i]);
            return 1;
        }

        fprintf(out_fp, "Accuracy  Percentage\n"); // 添加表头

        while (fgets(buffer, 1024, fp)) {
            result = strstr(buffer, "Accuracy: ");
            if (result != NULL) {
                sscanf(result + strlen("Accuracy: "), "%f", &accuracy);
                fprintf(out_fp, "%.2f ", accuracy); // 写入accuracy值
            }
            result = strstr(buffer, "Percentage of data from benign programs: ");
            if (result != NULL) {
                sscanf(result + strlen("Percentage of data from benign programs: "), "%f", &percentage);
                fprintf(out_fp, "%.2f\n", percentage); // 写入percentage值并换行
            }
        }

        fclose(fp);
        fclose(out_fp);
    }

    return 0;
}
