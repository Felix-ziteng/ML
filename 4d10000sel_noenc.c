#include <stdio.h>
#include <stdlib.h>

// #define COLS 9
#define COLS 4
#define ROWS 10000

// branch_cnt.txt  btaken_cnt.txt  clk_cnt.txt  instr_cnt.txt  jump_cnt.txt  ld_cnt.txt  ls_cnt.txt  rcv_cnt.txt  st_cnt.txt

int main(int argc, char* argv[])    
{   
    int data[ROWS][COLS];
    int i, j;
    
    
    if (argc < 5)
    {
        /* code */
        printf("Please provide the file name as a parameter.\n");
    }
    
    
    // 打开第一个文件
    FILE *file1 = fopen(argv[1], "r");
    if (file1 == NULL) {
        printf("无法打开文件1！\n");
        return 1;
    }
    
    // 读取第一个文件中的数据
    for (i = 0; i < ROWS; i++) {
        fscanf(file1, "%d", &data[i][0]);
    }
    
    // 关闭第一个文件
    fclose(file1);
    
    // 打开第二个文件
    FILE *file2 = fopen(argv[2], "r");
    if (file2 == NULL) {
        printf("无法打开文件2！\n");
        return 1;
    }
    
    // 读取第二个文件中的数据
    for (i = 0; i < ROWS; i++) {
        fscanf(file2, "%d", &data[i][1]);
    }
    
    // 关闭第二个文件
    fclose(file2);

    // 打开第三个文件
    FILE *file3 = fopen(argv[3], "r");
    if (file3 == NULL) {
        printf("无法打开文件3！\n");
        return 1;
    }

    // 读取第三个文件中的数据
    for (i = 0; i < ROWS; i++) {
        fscanf(file3, "%d", &data[i][2]);
    }
    
    // 关闭第三个文件
    fclose(file3);

    // 打开第四个文件
    FILE *file4 = fopen(argv[4], "r");
    if (file4 == NULL) {
        printf("无法打开文件4！\n");
        return 1;
    }
    
    // 读取第四个文件中的数据
    for (i = 0; i < ROWS; i++) {
        fscanf(file4, "%d", &data[i][3]);
    }

    // 关闭第四个文件
    fclose(file4);
    
    // 将数据写入新文件
    FILE *output_file = fopen("/home/cristiano/Documents/pulp-sdk/tests/qsort/noencrypt/parameters_learn/samples.txt", "w");
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
