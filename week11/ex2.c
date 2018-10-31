#include <stdio.h>
#include <zconf.h>

int main() {
    setvbuf(stdout, NULL, _IOFBF, 1024);

    printf("H");
    sleep(1);
    printf("e");
    sleep(1);
    printf("l");
    sleep(1);
    printf("l");
    sleep(1);
    printf("o");

    return 0;
}