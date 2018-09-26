#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include <signal.h>


int main() {
    pid_t pid = fork();
    if (pid == 0) {
        while (1) {
            fflush(stdout);
            printf("I am alive\n");
            sleep(1);
        }
    }
    if (pid > 0) {
        sleep(10);
        kill(pid, SIGTERM);
    }

    return 0;
}