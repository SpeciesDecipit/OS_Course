#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <zconf.h>


#define TRUE 1
#define FALSE 0
#define N 10

int count = 0;
int producer_is_active = TRUE;
int consumer_is_active = FALSE;

int produce_item() {
    return 0;
}

void insert_item(int item) {}

int remove_item() { return 0; }

void sleep_thread(int *status) {
    *status = FALSE;
    while (*status == FALSE) {
        if (status == &producer_is_active) {
            printf("Counter: %d\tProducer is sleeping\n", count);
//            sleep(10);
        }
        if (status == &consumer_is_active) {
            printf("Counter: %d\tConsumer is sleeping\n", count);
//            sleep(10);
        }
    }
}

void wakeup_thread(int *status) {
    if (*status == FALSE) *status = TRUE;
}

void *producer(void) {
    int item;

    while (TRUE) {
        item = produce_item();
        if (count == N) sleep_thread(&producer_is_active);
        insert_item(item);
        count++;

        printf("Item was inserted\n");

        if (count == 1) wakeup_thread(&consumer_is_active);
    }
}

void *consumer(void) {
    int item;
    while (TRUE) {
        if (count == 0) sleep_thread(&consumer_is_active);
        item = remove_item();
        count--;

        printf("Item was removed\n");

        if (count == N - 1) wakeup_thread(&producer_is_active);
    }
}


int main() {
    pthread_t customer_thread, producer_thread;
     pthread_create(&producer_thread, NULL, producer, NULL);
     pthread_create(&customer_thread, NULL, consumer, NULL);

     pthread_exit(NULL);
}