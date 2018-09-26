#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>


void sigkill_handler() {
    printf("Killing...\n");
    exit(1);
}


void sigusr1_handler() {
    printf("SIGUSR1 is catched...\n");
}

int main() {
    signal(SIGKILL, (void (*)(int)) sigkill_handler);
    signal(SIGSTOP, SIG_DFL);
    signal(SIGUSR1, (void (*)(int)) sigusr1_handler);

    while (1) {
        sleep(1);
    }

    return 0;
}