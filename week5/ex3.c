#include <stdio.h>
#include <time.h>
#include <pthread.h>

#define TRUE 1
#define N 10

int count = 0;
char buffer[N];
int i = 0;
pthread_mutex_t the_mutex;
pthread_cond_t condc, condp;

void *producer(void *ptr) {

    while (TRUE) {
        pthread_mutex_lock(&the_mutex);

        if (count == N) {
            pthread_cond_wait(&condp, &the_mutex);
        }
        buffer[count] = 'p';
        count = count + 1;


        if (count == 1) {
            pthread_cond_signal(&condc);
            pthread_mutex_unlock(&the_mutex);
        }
    }
}

void *consumer(void *ptr) {
    while (TRUE) { /* repeat forever */
        pthread_mutex_lock(&the_mutex);
        if (count == 0) {
            pthread_cond_wait(&condc, &the_mutex);
        }
        buffer[count] = 'c';
        count = count - 1;
        if (count == N - 1) {
            pthread_cond_signal(&condp);
            pthread_mutex_unlock(&the_mutex);
        }
    }
}


int main(int argc, char const *argv[]) {
    pthread_t pro, con;
    pthread_mutex_init(&the_mutex, 0);
    pthread_cond_init(&condc, 0);
    pthread_cond_init(&condp, 0);
    pthread_create(&con, 0, consumer, 0);
    pthread_create(&pro, 0, producer, 0);
    pthread_join(pro, 0);
    pthread_join(con, 0);
    pthread_cond_destroy(&condc);
    pthread_cond_destroy(&condp);
    pthread_mutex_destroy(&the_mutex);

    return 0;

}