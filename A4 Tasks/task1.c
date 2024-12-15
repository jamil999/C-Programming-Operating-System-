#include <pthread.h>
#include <stdio.h>
#include <unistd.h> 
#include <string.h>

#define MAX 10 // producers and consumers can produce and consume up to MAX
#define BUFLEN 6
#define NUMTHREAD 2 /* number of threads */

void *consumer(void *id);
void *producer(void *id);

char buffer[BUFLEN];
char source[BUFLEN]; // from this array producer will store its production into buffer
int pCount = 0;
int cCount = 0;
int buflen;

// initializing pthread mutex and condition variables
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty = PTHREAD_COND_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
int thread_id[NUMTHREAD] = {0, 1};
int i = 0;
int j = 0;

int main()
{
    int i;
    /* define the type to be pthread */
    pthread_t thread[NUMTHREAD];

    strcpy(source, "abcdef");
    buflen = strlen(source);
    /* create 2 threads */
    /* create one consumer and one producer */
    /* define the properties of multi threads for both threads  */
  
    pthread_mutex_init(&count_mutex, NULL);
    pthread_cond_init(&nonEmpty, NULL);
    pthread_cond_init(&full, NULL);

    pthread_create(&thread[0], NULL, producer, &thread_id[0]); 
    pthread_create(&thread[1], NULL, consumer, &thread_id[1]);
    
    for (i = 0; i < NUMTHREAD; i++)
    {
        pthread_join(thread[i], NULL);
    }
  
    pthread_mutex_destroy(&count_mutex);
    pthread_cond_destroy(&nonEmpty);
    pthread_cond_destroy(&full);

    return 0;
}

void *producer(void *id)
{
    int *theid = (int *)id;
    int pid = *theid;

    while (pCount < MAX)
    {
        pthread_mutex_lock(&count_mutex);

        while (BUFLEN <= i)
        {
            pthread_cond_wait(&full, &count_mutex);
        }

        int target = pCount % buflen;
        buffer[i] = source[target];
        printf("%d produced %c by Thread %d\n", pCount, buffer[i], pid);
        i++;
        pCount++;

        pthread_cond_signal(&nonEmpty);
        pthread_mutex_unlock(&count_mutex);
        sleep(1);
    }

    pthread_exit(NULL);
}

void *consumer(void *id)
{
    int *theid2 = (int *)id;
    int cid = *theid2;

    while (cCount < MAX)
    {
        pthread_mutex_lock(&count_mutex);
        while (i == 0 || i < 0)
        {
            pthread_cond_wait(&nonEmpty, &count_mutex);
        }
        int con = i - 1;
        
        printf("%d consumed %c by Thread %d\n", cCount, buffer[con], cid);
        cCount++;
        i = i - 1;
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&count_mutex);
    }

    pthread_exit(NULL);
}