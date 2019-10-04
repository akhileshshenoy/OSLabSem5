#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 40
int buf[BUF_SIZE],pHead,cHead,item;
sem_t empty,full,mutex;

void* produce(void* arg){

	while(1){
	
		sem_wait(&empty);
		sem_wait(&mutex);
		
		pHead = (pHead+1)%BUF_SIZE;
		buf[pHead] = item;
		printf("\nProduced %d",item);
		item++;

		sem_post(&mutex);
		sem_post(&full);
		
		sleep(1);
	}
}

void* consume(void* arg){

	while(1){

		sem_wait(&full);
		sem_wait(&mutex);
		
		cHead = (cHead+1)%BUF_SIZE;
		printf("\nConsumed %d",buf[cHead]);

		sem_post(&mutex);
		sem_post(&empty);
		
		sleep(1);
	}
}

int main(){

	pthread_t producer;
	pthread_t consumer;

	sem_init(&mutex,0,1);
	sem_init(&full,0,0);
	sem_init(&empty,0,11);

	pthread_create(&producer,NULL,&produce,NULL);
	pthread_create(&consumer,NULL,&consume,NULL);

	pthread_join(producer,NULL);
	pthread_join(consumer,NULL);

	return 0;
}
	
	
		
