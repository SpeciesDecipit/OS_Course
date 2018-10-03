#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main() {
    srand((unsigned int) time(NULL));

    int size, *array;
    printf("Enter original array size: ");
    scanf("%d", &size);

    printf("Original array: ");
    array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = 100;
        printf("%d ", array[i]);
    }

    printf("\n\nEnter new array size: ");
    scanf("%d", &size);

    printf("Reallocated array: ");
    array = realloc(array, size * sizeof(int));
    for (int i = 0; i < size; i++) {
        if (array[i] != 100)
            array[i] = 0;
        printf("%d ", array[i]);
    }

    return 0;
}