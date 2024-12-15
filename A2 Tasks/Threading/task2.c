#include <stdio.h>
#include <pthread.h>
int val = 1;

void* val_increment(int* arg) {

    for (int i = 0; i < 5; i++) {
    printf("Thread %d prints %d\n", *arg,val);
    val++;
    }
}

int main() {
    pthread_t five_threads[5];
    int thread_nums[5] = {0,1, 2, 3, 4};

    for (int i = 0; i < 5; i++) {
        pthread_create(&five_threads[i], NULL, (void*)val_increment, &thread_nums[i]);
        pthread_join(five_threads[i], NULL);
    }
    return 0;
}
