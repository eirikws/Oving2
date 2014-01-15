#include <pthread.h>
#include <stdio.h>

int i = 0;
pthread_mutex_t mymutex;
void* adder(){
    for(int x = 0; x < 1000000; x++){
        pthread_mutex_lock(&mymutex);
        i++;
        pthread_mutex_unlock(&mymutex);
    }
    return NULL;
}

void* decr(){
    for (int x=0; x < 1000000; x++){
        pthread_mutex_lock(&mymutex);
        i--;
        pthread_mutex_unlock(&mymutex);
    }return NULL;
}

int main(){
    
    pthread_t adder_thr;
    pthread_t decr_thr;
    pthread_create(&decr_thr,NULL,decr,NULL);
    pthread_create(&adder_thr, NULL, adder, NULL);
    for(int x = 0; x < 50; x++){
        printf("%i\n", i);
    }

    
    pthread_join(adder_thr, NULL);
    pthread_join(decr_thr,NULL);
    pthread_mutex_destroy(&mymutex);
    printf("Done: %i\n", i);
    return 0;
    
}
