#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main() {
    pid_t pid = fork();

    if (pid > 0) {
        printf("Hello from Parent [%d]\n", getpid());
    } else {
        printf("Hello from Child [%d]\n", getpid());
    }
    return 0;
}