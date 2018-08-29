#include <strings.h>
#include <stdio.h>

#define BUF_SIZE 1024

char *strrev(char *str) {
    int i = (int)strlen(str) - 1, j = 0;

    char ch;
    while (i > j) {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

int main() {
    char str[BUF_SIZE];
    printf("Input string: ");
    fgets(str, BUF_SIZE, stdin);
    str[strlen(str) - 1] = '\0';
    strrev(str);
    printf("Reverse string: %s", str);
}