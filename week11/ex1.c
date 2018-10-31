#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdio.h>

int main() {
    int fd = open("ex1.txt", O_RDWR | O_CREAT, 'w');
    const char *text = "This is a nice day!!!";
    size_t text_size = strlen(text) + 1;
    char *map = mmap(0, text_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    memcpy(map, text, strlen(text));
    msync(map, text_size, MS_SYNC);
    munmap(map, text_size);
    close(fd);
    return 0;
}