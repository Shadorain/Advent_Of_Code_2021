#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FILE_SIZE 1000

struct Submarine {
    int horizontal;
    int depth;
    int aim;
};

struct Commands {
    char cmd[8];
    int dist;
};


struct Commands data[FILE_SIZE];
struct Submarine sub;

void read_file (char *path) {
    FILE *fp = fopen(path, "r");
    for (int i = 0; i < FILE_SIZE; i++) {
        fscanf(fp, "%s %d", data[i].cmd, &data[i].dist);
        /* printf("%s %d\n", data[i].cmd, data[i].dist); */
    };
    fclose(fp);
}

void compute () {
    int x = 0;
    for (int i = 0; i < FILE_SIZE; i++) {
        x = data[i].dist;
        if (strcmp("forward", data[i].cmd) == 0) { 
            sub.horizontal += x;
            sub.depth += sub.aim * x;
        }
        else if (strcmp("down", data[i].cmd) == 0) sub.aim += x;
        else if (strcmp("up", data[i].cmd) == 0) sub.aim -= x;
    }
}

int main () {
    char *path = "./input";

    read_file(path);

    compute();
    printf("Depth: %d, Horizontal: %d\n", sub.depth, sub.horizontal);
    printf("Total: %d\n", (sub.horizontal*sub.depth));
}
