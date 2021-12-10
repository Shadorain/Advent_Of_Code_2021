#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FILE_SIZE 1000
#define COLUMNS 12

struct Submarine {
    int gamma;
    int epsilon;
};

char data[FILE_SIZE][COLUMNS];
struct Submarine sub;

void read_file (char *path) {
    FILE *fp = fopen(path, "r");
    for (int i = 0; i < FILE_SIZE; i++) {
        fscanf(fp, "%s", data[i]);
        printf("%s\n", data[i]);
    };
    fclose(fp);
}

int bin2dec (char *bin) {
	long result = 0;
	int bit = 0, n = strlen(bin)-1;

	while (n >= 0) {
		if (bin[n] == '1')
			result += (1 << (bit));
		n--;
		bit++;
	}
	return result;
}

int notbin (char *bin) {
	char ret[12] = "111111111111";
	int bit = 0, n = strlen(bin)-1;

	while (n >= 0) {
		if (bin[n] == '1') ret[n] = '0';
		n--;
	}
	return bin2dec(ret);
}

void compute () {
    int zero, ones, j = 0;
    char gamma[12] = "000000000000";
    for (int j = 0; j < COLUMNS; j++) {
        zero = 0, ones = 0;
        for (int i = 0; i < FILE_SIZE; i++) {
            if (data[i][j] == '0') zero++;
            else if (data[i][j] == '1') ones++;
        }
        if (ones > zero) gamma[j] = '1';
    }
    sub.gamma = bin2dec(gamma);
    sub.epsilon = notbin(gamma);
}

int main () {
    char *path = "./input";

    read_file(path);

    compute();
    printf("Gamma: %d, Epsilon: %d\n", sub.gamma, sub.epsilon);
    printf("Total: %d\n", (sub.gamma*sub.epsilon));
}
