#include <stdio.h>

int main() {
    char **s;
    char foo[] = "Hello World";
    s = foo;                // HERE WAS MISTAKE WHICH OCCURS SEGMENTATION FAULT
    printf("s is %s\n", s);
    s[0] = foo;
    printf("s[0] is %s\n",s[0]);
    return 0;
}