#include <stdio.h>
#include <pthread.h>
int thread_nums[5] = {1, 2, 3, 4, 5};
void* thread_status(void* arg) {
    int* num = (int*)arg;
    printf("thread-%d running\n", *num);
    printf("thread-%d closed\n", *num);
    return NULL;
}

int main() {
    pthread_t five_threads[5];
    for (int i = 0; i < 5; i++) {
        pthread_create(&five_threads[i], NULL, (void*)thread_status, (void*)&thread_nums[i]);
        pthread_join(five_threads[i], NULL);
    }
    return 0;
}
