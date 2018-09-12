#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define N 5

int main() {


    for (int i = 0; i < N; i++) {
        fork();
    }

    sleep(5);

    return 0;
}