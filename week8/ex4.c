#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include <string.h>
#include <sys/resource.h>

// 10 MB in Bytes
#define SIZE 10485760

#define N 10

int main() {
    struct rusage usage;

    for (int i = 0; i < N; i++) {
        int *ptr = malloc(SIZE * sizeof(char));
        memset(ptr, 0, SIZE);
        getrusage(RUSAGE_SELF, &usage);
        fflush(stdout);
        printf("Maximum resident set size: %d\n", (int) usage.ru_maxrss);
        printf("Integral shared memory size: %d\n", (int) usage.ru_ixrss);
        printf("Integral unshared data size: %d\n", (int) usage.ru_idrss);
        printf("Integral unshared stack size: %d\n", (int) usage.ru_isrss);
        printf("-----------------------------------------------------------\n");
        sleep(1);
    }
    return 0;
}