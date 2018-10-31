#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdio.h>



int main() {
    int source_file, dest_file;
    char *src, *dest;
    size_t filesize;

    source_file = open("ex4.txt", O_RDONLY);
    filesize = (size_t) lseek(source_file, 0, SEEK_END);

    src = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE, source_file, 0);

    dest_file = open("ex4.memcpy.txt", O_RDWR | O_CREAT, 0666);

    ftruncate(dest_file, (off_t) filesize);

    dest = mmap(NULL, filesize, PROT_READ | PROT_WRITE, MAP_SHARED, dest_file, 0);

    memcpy(dest, src, filesize);

    munmap(src, filesize);
    munmap(dest, filesize);

    close(source_file);
    close(dest_file);

    return 0;
}