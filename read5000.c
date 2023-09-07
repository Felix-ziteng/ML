#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10000

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Please provide the file name as a parameter.\n");
        return 1;
    }

    char* filename = argv[1];
    FILE* file = fopen(filename, "r");

    if (!file) {
        printf("Failed to open file %s.\n", filename);
        return 1;
    }

    // Read the first 5000 values
    int values[MAX_LENGTH];
    int count = 0;
    while (count < MAX_LENGTH && fscanf(file, "%d", &values[count]) != EOF) {
        count++;
    }

    // Close the file
    fclose(file);

    // Write the first 5000 values back to the file
    file = fopen(filename, "w");
    if (!file) {
        printf("Failed to open file %s.\n", filename);
        return 1;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d\n", values[i]);
    }

    // Close the file
    fclose(file);

    printf("Done.\n");
    return 0;
}
