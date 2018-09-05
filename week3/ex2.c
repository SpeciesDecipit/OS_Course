#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int buf = *a;
    *a = *b;
    *b = buf;
}

void bubble_sort(int array[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
}

void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i != size - 1)
            printf(", ");
    }

}

void scanf_array(int array[], int size) {
    for (int i = 0; i < size; i++)
        scanf("%d", &array[i]);
}

int main() {
    int size;
    int *array;

    printf("Input size of array: ");
    scanf("%d", &size);

    array = (int*)malloc(sizeof(int) * size);

    printf("Input elements of array: ");
    scanf_array(array, size);

    printf("Sorting array...\n");
    bubble_sort(array, size);

    printf("Sorted array:\n");
    print_array(array, size);

    return 0;
}