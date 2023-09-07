#include <stdio.h>
#include <stdlib.h>

#define COLS 9
#define ROWS 100


int main() {
    int data[ROWS][COLS];
    int i, j;

    // 打开第一个文件
    FILE* file1 = fopen("instr_cnt.txt", "r");
    if (file1 == NULL) {
        printf("无法打开文件 instr_cnt.txt！\n");
        return 1;
    }

    // 读取第一个文件中的数据
    for (i = 0; i < ROWS; i++) {
        fscanf(file1, "%d", &data[i][0]);
    }

    // 关闭第一个文件
    fclose(file1);

    // 打开其他文件
    char* filenames[COLS - 1] = {
        "clk_cnt.txt",
        "branch_cnt.txt",
        "btaken_cnt.txt",
        "jump_cnt.txt",
        "ld_cnt.txt",
        "ls_cnt.txt",
        "rcv_cnt.txt",
        "st_cnt.txt",
    };
    for (j = 1; j < COLS; j++) {
        FILE* file = fopen(filenames[j - 1], "r");
        if (file == NULL) {
            printf("无法打开文件 %s！\n", filenames[j - 1]);
            return 1;
        }

        // 读取文件中的数据
        for (i = 0; i < ROWS; i++) {
            fscanf(file, "%d", &data[i][j]);
        }

        // 关闭文件
        fclose(file);
    }

    // 将数据写入新文件
    FILE* output_file = fopen("/home/cristiano/Documents/pulp-sdk/tests/qsort/noencrypt/parameters/samples.txt", "w");
    if (output_file == NULL) {
        printf("无法打开输出文件！\n");
        return 1;
    }

    // 将数据写入新文件
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            fprintf(output_file, "%d ", data[i][j]);
        }
        fprintf(output_file, "\n");
    }

    // 关闭输出文件
    fclose(output_file);

    printf("数据已经成功写入输出文件！\n");

    return 0;
}
