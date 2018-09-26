#include <zconf.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
    pid_t pid_child1, pid_child2;
    int p[2];

    pipe(p);

    pid_child1 = fork();

    if (pid_child1 == 0) {
        close(p[1]);
        int data;

        read(p[0], &data, sizeof(data));
        printf("Children 1:\n\tSelf PID: %d, PID of 2nd children (got from parent): %d\n", getpid(), data);

        sleep(3);

        kill(data, SIGSTOP);
    } else {
        pid_child2 = fork();

        if (pid_child2 == 0) {
            while (1);
        } else {
            close(p[0]);
            int status;

            printf("Parent:\n\tChildren forked with PID: %d\n", pid_child1);
            printf("Parent:\n\tChildren forked with PID: %d\n", pid_child2);

            write(p[1], &pid_child2, sizeof(pid_child2));
            waitpid(pid_child2, &status, NULL);

            printf("Children 2 terminate by Children 1\n");
        }
    }

    return 0;
}