#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void* ascii_cal(void* arg) {
    char* nuser = (char*)arg;
    int length = strlen(nuser);
    static int total; 
    total = 0;
    for (int i = 0; i < length; i++) {
        total += nuser[i];
    }
    return (void*)&total; 
}

void* print_hasta(void* arg){
    printf("Hasta la vista\n");
    return NULL;
}

int main() {
    pthread_t three_threads[3];
    char* user1 = "Jamil";
    char* user2 = "Hossain";
    char* user3 = "niassoH";
    
    int* total1;
    int* total2;
    int* total3;
    
    int check1,check2,check3;
    

    pthread_create(&three_threads[0], NULL, ascii_cal, (void*)user1);
    pthread_join(three_threads[0], (void*)&total1);
    //printf("total1 %d\n", *total1);
    check1 = *total1;

    pthread_create(&three_threads[1], NULL, ascii_cal, (void*)user2);
    pthread_join(three_threads[1], (void*)&total2);
    //printf("total2 %d\n", *total2);
    check2 = *total2;

    pthread_create(&three_threads[2], NULL, ascii_cal, (void*)user3);
    pthread_join(three_threads[2], (void*)&total3);
    //printf("total3 %d\n", *total3);
    check3 = *total3;

    if (check1 == check2 && check1 == check3) {
        printf("Eureka\n");
    } else if (check1 == check2 || check1 == check3 || check2 == check3) {
        printf("Miracle\n");
    } else {
        pthread_t another_one;
        pthread_create(&another_one, NULL, print_hasta, NULL);
        pthread_join(another_one, NULL);
    }
    return 0;
}
