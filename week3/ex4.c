#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int buf = *a;
    *a = *b;
    *b = buf;
}

void quicksort(int *array, int start, int end) {
    if (start < end) {
        int l = start + 1;
        int r = end;
        int p = array[start];

        while (l < r) {
            if (array[l] <= p)
                l++;
            else if (array[r] >= p)
                r--;
            else
                swap(&array[l], &array[r]);
        }

        if (array[l] < p) {
            swap(&array[l], &array[start]);
            l--;
        } else {
            l--;
            swap(&array[l], &array[start]);
        }
        quicksort(array, start, l);
        quicksort(array, r, end);
    }
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

    array = (int *) malloc(sizeof(int) * size);

    printf("Input elements of array: ");
    scanf_array(array, size);

    printf("Sorting array...\n");
    quicksort(array, 0, size - 1);

    printf("Sorted array:\n");
    print_array(array, size);

    return 0;
}