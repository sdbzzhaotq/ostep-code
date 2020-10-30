#include <stdio.h>
#include <pthread.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c = PTHREAD_COND_INITIALIZER;

int done = 0;

void thr_exit() {
    pthread_mutex_lock(&m);
    done = 1;
    pthread_cond_signal(&c);
    pthread_mutex_unlock(&m);
    return;
}

void thr_join() {
    pthread_mutex_lock(&m);
    while(done == 0) {
        pthread_cond_wait(&c,&m);
    }
    pthread_mutex_unlock(&m);
    return;
}


void* child(void* arg) {
    printf("child enter.\n");

    thr_exit();

    return NULL;
}


int main(int argc, char* argv[]) {

    printf("main enter.\n");
    pthread_t p;

    pthread_create(&p, NULL, child, NULL);

    thr_join();

    printf("main leave.\n");
    return 0;
}