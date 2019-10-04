#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(){

	sem_t wrt,mutex;
	sem_init(&wrt,0,1);
	sem_init(&mutex,0,1);

	int readcount = 0;
	int item = 0;

	void *readItem(void* arg){

		while(1){
			sem_wait(&mutex);
		
			readcount++;

			if(readcount==1) sem_wait(&wrt);

			sem_post(&mutex);

			printf("\n READ %d",item);

			sem_wait(&mutex);

			readcount--;
			if(!readcount) sem_post(&wrt);

			sem_post(&mutex);
			sleep(rand()%(6-1 +1)+1);
		}
	}

	void* writeItem(void* arg){

		while(1){
			sem_wait(&wrt);
			printf("\nWriting item : %d",++item);
			sem_post(&wrt);
			sleep(rand()%(3-1 +1)+1);
		}
	}

	int nReader = 5;
	int nWriter = 2;

	pthread_t reader[nReader];
	pthread_t writer[nWriter];

	for(int i=0;i<nWriter;i++)
		pthread_create(writer+i,NULL,&writeItem,NULL);
	for(int i=0;i<nReader;i++)
		pthread_create(reader+i,NULL,&readItem,NULL);

	for(int i=0;i<nReader;i++)
		pthread_join(reader[i],NULL);
	for(int i=0;i<nWriter;i++)
		pthread_join(writer[i],NULL);

	return 0;
}

