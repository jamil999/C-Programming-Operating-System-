#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

/*
This program provides a possible solution using mutex and semaphore.
use 5 Farmers and 5 ShopOwners to demonstrate the solution.
*/
#define MaxCrops 5 // Maximum crops a Farmer can produce or a Shpoowner can take
#define warehouseSize 5 // Size of the warehouse
sem_t empty;
sem_t full;
int in = 0;
int out = 0;
char crops[warehouseSize]={'R','W','P','S','M'}; //indicating room for different crops
char warehouse[warehouseSize]={'N','N','N','N','N'}; //initially all the room is empty
pthread_mutex_t mutex;

void *Farmer(void *far)
{   
  
    int i = 0;
    while (i < MaxCrops)
    {
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    
    char warin = crops[in];
    warehouse[in] = warin;
    int fid = *((int *)far);
    printf("Farmer %d: Insert crops %c at %d\n", fid, warin, in);
    
    in = (in + 1) % warehouseSize;
    
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    i++;
    }
  int sownernum2 = *((int*)far);
  printf("Farmer%d: ",sownernum2);
  int count2 = 0;
  while (count2 < warehouseSize) {
   printf("%c", warehouse[count2]);
   count2++;
  }
  printf("\n");
}

void *ShopOwner(void *sho)
{   
    int i = 0;
    while (i < MaxCrops)
    {
   
    
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    
    char crop = warehouse[out];
    int ownernum = *((int*)sho);  
      
      
    printf("Shop owner %d: Remove crops %c from %d\n", ownernum , crop, out);
    warehouse[out] = 'N';
    out = (out + 1) % warehouseSize;
    
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
      
    i++;
    }
  
  int ownernum2 = *((int*)sho);
  printf("ShopOwner%d: ",ownernum2);
  int count = 0;
  while (count < warehouseSize) {
   printf("%c", warehouse[count]);
   count++;
  }
  printf("\n");
}

int main()
{   
    /*initializing thread, mutex, semaphore*/
    pthread_t Far[5], Sho[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, warehouseSize); //when the warehouse is full thread will wait
    sem_init(&full, 0, 0); //when the warehouse is empty thread will wait

    int a[5] = {1, 2, 3, 4, 5}; //Just used for numbering the Farmer and ShopOwner

    /*create 5 thread for Farmer 5 thread for ShopOwner*/
    for (int i = 0; i < 5; i++) {
    pthread_create(&Far[i], NULL, (void *)Farmer, (void *)&a[i]);
    }
    for (int i = 0; i < 5; i++) {
   pthread_create(&Sho[i], NULL, (void *)ShopOwner, (void *)&a[i]);
    }
    // Joining threads
    for (int i = 0; i < 5; i++) {
        pthread_join(Far[i], NULL);
    }
    for (int i = 0; i < 5; i++) {
        pthread_join(Sho[i], NULL);
    }

    // Closing or destroying mutex and semaphore
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}