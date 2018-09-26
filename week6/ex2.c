#include <stdio.h>
#include <zconf.h>

#define BUF_SIZE 1024

int main() {
    int fd[2];
    char parent_str[BUF_SIZE];
    char child_str[BUF_SIZE];

    pipe(fd);

    scanf("%s", parent_str);

    pid_t pid = fork();

    if (pid == 0) {
        close(fd[1]);
        read(fd[0], child_str, BUF_SIZE + 1);
        close(fd[0]);

    } else {
        close(fd[0]);
        write(fd[1], parent_str, BUF_SIZE + 1);
        close(fd[1]);

        printf("%s", parent_str);
    }

    return 0;
}