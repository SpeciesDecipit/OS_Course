#include <stdio.h>

void swap(int *a, int *b) {
    int buf = *a;
    *a = *b;
    *b = buf;
}

int main() {
    int a, b;

    printf("Input 1st number: ");
    scanf("%d", &a);
    printf("Input 2nd number: ");
    scanf("%d", &b);

    swap(&a, &b);

    printf("1st number: %d\n", a);
    printf("2nd number: %d", b);

    return 0;
}