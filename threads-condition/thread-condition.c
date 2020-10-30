#include <assert.h>
#include <stdio.h>
#include <pthread.h>

void* thread_1_func(void* arg) {
  while(1) {
    ;
  }
  return NULL;
}

void* thread_2_func(void* arg) {
  while(1) {
    ;
  }
  return NULL;
}

int main(int argc, char* argv[]) {

  pthread_t p1;
  pthread_t p2;
  int rc = 0;
  rc = pthread_create(&p1, NULL, thread_1_func, NULL);
  assert(rc == 0);
  rc = pthread_create(&p2, NULL, thread_2_func, NULL);
  assert(rc == 0);
  return 0;
}
