#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main() {
    int n = 10;

    pid_t pid = fork();

    if (pid > 0) {
        printf("Hello from Parent [%d - %d]\n", getpid(), n);
    } else {
        printf("Hello from Child [%d - %d]\n", getpid(), n);
    }
//    printf("\n");
    return 0;
}