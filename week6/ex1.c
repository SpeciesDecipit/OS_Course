#include <zconf.h>
#include <stdio.h>

#define BUF_SIZE 1024

int main() {
    int fd[2];
    char in_str[BUF_SIZE];
    char out_str[BUF_SIZE];

    pipe(fd);

    scanf("%s", in_str);

    write(fd[1], in_str, BUF_SIZE + 1);
    read(fd[0], out_str, BUF_SIZE + 1);

    printf("%s", out_str);

    return 0;
}