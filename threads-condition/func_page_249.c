#include <assert.h>
#include <stdio.h>
#include <pthread.h>

volatile int done = 0;

void* child(void* arg) {
    printf("child begin\n");
    done = 1;
    printf("child end\n");
    return NULL;
}


int main(int argc, char* argv[]){
    
    printf("main begin.\n");

    pthread_t thr;
    pthread_create(&thr,NULL,child,NULL);

    while(done == 0) {
        printf("waiting for child join.\n");
    }

    printf("main end.\n");

    return 0;
}