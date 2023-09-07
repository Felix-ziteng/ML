#include <stdio.h>
#include <stdlib.h>

#define ROWS 10000
#define COLS 9

// branch_cnt.txt  btaken_cnt.txt  clk_cnt.txt  instr_cnt.txt  jump_cnt.txt  ld_cnt.txt  ls_cnt.txt  rcv_cnt.txt  st_cnt.txt

int main()
{
    int data[ROWS][COLS];
    int i, j;
    
    // 打开第一个文件
    FILE *file1 = fopen("instr_cnt.txt", "r");
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
    FILE *file2 = fopen("clk_cnt.txt", "r");
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
    FILE *file3 = fopen("branch_cnt.txt", "r");
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
    FILE *file4 = fopen("btaken_cnt.txt", "r");
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

    // 打开第五个文件
    FILE *file5 = fopen("jump_cnt.txt", "r");
    if (file5 == NULL) {
        printf("无法打开文件5！\n");
        return 1;
    }

    // 读取第五个文件中的数据
    for (i = 0; i < ROWS; i++) {
        fscanf(file5, "%d", &data[i][4]);
    }
    
    // 关闭第五个文件
    fclose(file5);

    // 打开第六个文件
    FILE *file6 = fopen("ld_cnt.txt", "r");
    if (file6 == NULL) {
        printf("无法打开文件6！\n");
        return 1;
    }

    // 读取第六个文件中的数据
    for (i = 0; i < ROWS; i++) {
        fscanf(file6, "%d", &data[i][5]);
    }

    // 关闭第六个文件
    fclose(file6);

    // 打开第七个文件
    FILE *file7 = fopen("ls_cnt.txt", "r");
    if (file7 == NULL) {
        printf("无法打开文件7！\n");
        return 1;
    }

    // 读取第七个文件中的数据
    for (i = 0; i < ROWS; i++) {
        fscanf(file7, "%d", &data[i][6]);
    }

    // 关闭第七个文件
    fclose(file7);

    // 打开第八个文件
    FILE *file8 = fopen("rcv_cnt.txt", "r");
    if (file8 == NULL) {
        printf("无法打开文件8！\n");
        return 1;
    }

    // 读取第八个文件中的数据
    for (i = 0; i < ROWS; i++) {
        fscanf(file8, "%d", &data[i][7]);
    }

    // 关闭第八个文件
    fclose(file8);

    // 打开第九个文件
    FILE *file9 = fopen("st_cnt.txt", "r");
    if (file9 == NULL) {
        printf("无法打开文件9！\n");
        return 1;
    }

    // 读取第九个文件中的数据
    for (i = 0; i < ROWS; i++) {
        fscanf(file9, "%d", &data[i][8]);
    }

    // 关闭第九个文件
    fclose(file9);
    
    
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
