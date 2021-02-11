//run with gcc foo.c -std=c99 -lpthread
#include <pthread.h>
#include <stdio.h>

int i = 0;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

// Note the return type: void*
void* incrementingThreadFunction(){
    for (int j = 0; j < 1000000; j++) {
	    pthread_mutex_lock(&mtx);
	    i++;
        pthread_mutex_unlock(&mtx);
    }
    return NULL;
}

void* decrementingThreadFunction(){
    for (int j = 0; j < 999999; j++) {
        pthread_mutex_lock(&mtx);
	    i--;
        pthread_mutex_unlock(&mtx);
    }
    return NULL;
}


int main(){
    pthread_t incrementingThread, decrementingThread;

    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);
    
    pthread_join(incrementingThread, NULL);
    pthread_join(decrementingThread, NULL);
    
    printf("The magic number is: %d\n", i);


    pthread_mutex_destroy(&mtx);
    return 0;
}
