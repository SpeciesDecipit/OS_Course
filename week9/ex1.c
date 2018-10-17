#include <stdlib.h>
#include <stdio.h>


struct frame {
    int timespan;
    int reference;
    int page_number;
};

int extract_page(struct frame* pt, int page_number, int current) {
    for (int i = 0; i < current; i++) {
        if (pt[i].page_number == page_number)
            return i;
    }
    return -1;
}

struct frame create_frame(int page_number, int reference, int timespan) {
    struct frame fr;
    fr.page_number = page_number;
    fr.reference = reference;
    fr.timespan = timespan;

    return fr;
}

void update_page_table(struct frame* pt, int current) {
    for (int i = 0; i < current; i++) {
        pt[i].timespan = pt[i].timespan >> 1;
        if (pt[i].reference)
            pt[i].timespan = pt[i].timespan | 1 << (sizeof(int) - 1);
        pt[i].reference = 0;
    }
}

int remove_page(struct frame* pt, int size) {
    int min_ind = 0;
    for (int i = 1; i < size; i++) {
        if (pt[i].timespan < pt[min_ind].timespan)
            min_ind = i;
    }

    return min_ind;
}


int main(int argc, char* argv[]) {
    FILE *file = fopen("input.txt", "r");
    int curr_page, current = 0, size = atoi(argv[1]), total = 0, hit = 0, miss = 0, index = 0;
    struct frame* pt = malloc(sizeof(struct frame) * size);

    while (fscanf(file, " %d", &curr_page) == 1) {
        total++;
        if ((index = extract_page(pt, curr_page, current)) != -1) {
            hit++;
            pt[index].reference = 1;
            update_page_table(pt, current);
        } else {
            miss++;
            if (current < size) {
                pt[current] = create_frame(curr_page, 1, 0);
                current++;
                update_page_table(pt, current);
            } else {
                pt[remove_page(pt, size)] = create_frame(curr_page, 1, 0);
                update_page_table(pt, size);
            }
        }
    }

    printf("HIT RATE: %f", (double)miss/hit);

    fclose(file);
    return 0;
}