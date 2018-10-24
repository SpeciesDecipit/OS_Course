#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

#define PATH_MAX 1024

int main() {
    FILE *f = fopen("ex4.txt", "w");
    char cwd[PATH_MAX];
    getcwd(cwd, PATH_MAX);
    DIR *dirp = opendir(strcat(cwd, "/tmp"));
    struct dirent* de;

    while ((de = readdir(dirp)) != NULL) {
        char dir_name[PATH_MAX] = "tmp/";
        struct stat *restrict buf = malloc(sizeof(struct stat));
        stat(strcat(dir_name, de->d_name), buf);
        fprintf(f, "%s: %d\n", de->d_name, buf->st_nlink);
    }

    return 0;
}