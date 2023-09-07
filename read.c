#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main() {
    FILE *fp_in, *fp_out_instr, *fp_out_clk;
    char line[MAX_LINE_LENGTH];
    char *instr_cnt_str, *clk_cnt_str, *cpi_str, *cycles_imiss_str;
    int instr_cnt, clk_cnt, cycles_imiss;
    float cpi;

    fp_in = fopen("qsort.log", "r");
    if (fp_in == NULL) {
        printf("Error: could not open input file.\n");
        exit(EXIT_FAILURE);
    }

    fp_out_instr = fopen("parameters/instr_cnt.txt", "w");
    if (fp_out_instr == NULL) {
        printf("Error: could not open output file for instructions.\n");
        exit(EXIT_FAILURE);
    }

    fp_out_clk = fopen("parameters/clk_cnt.txt", "w");
    if (fp_out_clk == NULL) {
        printf("Error: could not open output file for clock cycles.\n");
        exit(EXIT_FAILURE);
    }


    while (fgets(line, MAX_LINE_LENGTH, fp_in) != NULL) {
        instr_cnt_str = strstr(line, "Number of Instructions:");
        if (instr_cnt_str != NULL) {
            instr_cnt_str += strlen("Number of Instructions:");
            instr_cnt = atoi(instr_cnt_str);
            fprintf(fp_out_instr, "%d\n", instr_cnt);
        }

        clk_cnt_str = strstr(line, "Clock Cycles:");
        if (clk_cnt_str != NULL) {
            clk_cnt_str += strlen("Clock Cycles:");
            clk_cnt = atoi(clk_cnt_str);
            fprintf(fp_out_clk, "%d\n", clk_cnt);
        }

    }

    fclose(fp_in);
    fclose(fp_out_instr);
    fclose(fp_out_clk);

    return 0;
}