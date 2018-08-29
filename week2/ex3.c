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

void print_triangle(int height) {
    for (int i = 0; i < height; i++) {
        print_level((2 * height - 2) / 2 - i, 2 * i + 1);
        printf("%c", '\n');
    }
}

void print_half_of_triangle(int height) {
    for (int i = 1; i <= height; i++) {
        print_level(0, i);
        printf("%c", '\n');
    }
}

void print_square(int height) {
    for (int i = 0; i < height; i++) {
        print_level(0, height);
        printf("%c", '\n');
    }
}

void print_half_of_rhombus(int height) {
    print_half_of_triangle(height);
    for (int i = height - 1; i >= 1; i--) {
        print_level(0, i);
        printf("%c", '\n');
    }
}

int main(int argc, char **argv) {
    int height = atoi(argv[1]);

    print_triangle(height);

    return 0;
}