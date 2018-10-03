#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    int *array;

    printf("Input size of array: ");
    scanf("%d", &size);

    array = malloc(size * sizeof(int));

    printf("Array: ");
    for (int i = 0; i < size; i++) {
        array[i] = i;
        printf("%d ", array[i]);
    }
}