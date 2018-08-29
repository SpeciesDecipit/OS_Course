#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a;
    float b;
    double c;

    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;

    printf("Size of integer: %d Max value: %d\n", (int)sizeof(a), a);
    printf("Size of float: %d Max value: %f\n", (int)sizeof(b), b);
    printf("Size of double: %d\t Max value: %f", (int)sizeof(c), c);
}