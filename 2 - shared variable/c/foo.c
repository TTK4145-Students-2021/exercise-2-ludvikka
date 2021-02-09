#include <pthread.h>
#include <stdio.h>

int i = 0;

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
    pthread_mutex_t mtx
    pthread_mutex_init(&mtx, NULL);


    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);
    
    pthread_join(incrementingThread, NULL);
    pthread_join(decrementingThread, NULL);
    
    printf("The magic number is: %d\n", i);


    pthread_mutex_destroy(&mtx);
    return 0;
}
