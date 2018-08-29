#include <stdio.h>
#include <stdlib.h>

void print_level(int half_of_width, int number_of_stars) {
    for (int i = 0; i < half_of_width; i++)
        printf(" ");
    for (int i = 0; i < number_of_stars; i++)
        printf("%c", '*');
    for (int i = 0; i < half_of_width; i++)
        printf(" ");
}

int main(int argc, char **argv) {
    int height = atoi(argv[1]);

    for (int i = 0; i < height; i++) {
        print_level((2 * height - 2) / 2 - i, 2 * i + 1);
        printf("%c", '\n');
    }

    return 0;
}