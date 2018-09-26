#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>


void signint_handler() {
    printf("Exiting...\n");
    exit(1);
}

int main() {
    signal(SIGINT, (void (*)(int)) signint_handler);

    while (1) {
        printf("Going to sleep for a second...\n");
        sleep(1);
    }

    return 0;
}