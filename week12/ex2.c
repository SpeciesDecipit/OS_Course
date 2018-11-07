#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int REWRITE = FALSE;

void parse_args(int argc, char *argv[]) {
    int opt;
    while ((opt = getopt(argc, argv, "a")) != -1) {
        switch (opt) {
            case 'a':
                REWRITE = TRUE;
        }
    }
}


int main(int argc, char *argv[]) {
    parse_args(argc, argv);
    FILE *output_file;
    int ch;

    if (REWRITE) {
        output_file = fopen(argv[argc - 1], "a");
    } else {
        output_file = fopen(argv[argc - 1], "w");
    }

    while (read(0, &ch, 1) > 0) {
        fprintf(output_file, "%c", ch);
        printf("%c", ch);
    }

    fclose(output_file);

    return 0;
}