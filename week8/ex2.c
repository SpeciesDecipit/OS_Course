#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include <string.h>

// 10 MB in Bytes
#define SIZE 10485760

#define N 10

int main() {
    for (int i = 0; i < N; i++) {
        int *ptr = malloc(SIZE * sizeof(char));
        memset(ptr, 0, SIZE);
        sleep(1);
    }
    return 0;
}