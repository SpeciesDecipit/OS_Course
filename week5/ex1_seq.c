#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 10

int thread_id[N];

void *printFromThread() {
    printf("Message was printing by thread with ID: %d\n", (int) pthread_self());
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    int rc;

    for (int i = 0; i < N; i++) {
        rc = pthread_create(&thread_id[i], NULL, printFromThread, NULL);
        pthread_join(thread_id[i], NULL);                       // Waiting till thread will terminate

        if (rc) {
            printf("\n ERROR: return code from pthread_create is %d \n", rc);
            exit(1);
        }

        printf("Thread with ID %d created by thread with ID %d\n", (int) thread_id[i], (int) pthread_self());

        sleep(1);
    }

    pthread_exit(NULL);
}