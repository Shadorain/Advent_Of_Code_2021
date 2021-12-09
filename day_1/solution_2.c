#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int data[2000];

void read_file (char *path) {
    FILE *fp = fopen(path, "r");
    int n = 0;
    for (int i = 0; i < 2000; i++) {
        fscanf(fp, "%d", &data[i]);
    };
    fclose(fp);
}

int compute_from_array () {
    int prev_tmp = -1, tmp = 0, total = 0;
    for (int i = 0; i < 2000; i++) {
        tmp = 0;
        for (int j = 0; j < 3; j++)
            tmp += data[i+j];

        if (prev_tmp != -1) if (prev_tmp < tmp) total += 1;
        prev_tmp = tmp;
    }
    return total;
}

int main () {
    int total = 0;
    char *path = "./input";

    read_file(path);

    printf("Total: %d\n", compute_from_array());
}
