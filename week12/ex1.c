#include <fcntl.h>
#include <ntsid.h>
#include <zconf.h>
#import <stdio.h>

int main() {
    int randomData = open("/dev/random", O_RDONLY);
    FILE *output = fopen("ex1.txt", "w");
    char myRandomData[50];
    size_t randomDataLen = 0;
    while (randomDataLen < sizeof myRandomData)
    {
        ssize_t result = read(randomData, myRandomData + randomDataLen, (sizeof myRandomData) - randomDataLen);
        if (result < 0) {
            printf("ERROR");
        }
        randomDataLen += result;
    }
    close(randomData);
    fprintf(output, "%s", myRandomData);
    return 0;
}