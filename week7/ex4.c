#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

#define ORIGINAL_SIZE 10
#define NEW_SIZE 20


void *my_realloc(int *ptr, size_t new_size) {
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
    if (ptr == NULL)
        return malloc(new_size);

    void *new_ptr = malloc(new_size);
    memcpy(new_ptr, ptr, new_size);
    free(ptr);

    return new_ptr;
}

int main() {
    int *array = malloc(ORIGINAL_SIZE * sizeof(int));

    printf("Original array: ");
    for (int i = 0; i < ORIGINAL_SIZE; i++) {
        array[i] = i;
        printf("%d ", array[i]);
    }

    array = my_realloc(array, NEW_SIZE * sizeof(int));

    printf("\nReallocated array: ");
    for (int i = 0; i < NEW_SIZE; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}