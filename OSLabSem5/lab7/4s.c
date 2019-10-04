#include <stdio.h>

#include <sys/shm.h>
#include <sys/types.h>

#include <unistd.h>
#include <stdlib.h>

#define PA 1
#define PB 2

struct s {
    int turn;
    int n;
    char words[40];
} *shm;

int main(void)
{
    int shmid = shmget((key_t) 1234, sizeof(struct s), 0666 | IPC_CREAT);
    shm = (struct s *) shmat(shmid, (void *) 0, 0);
	printf("%p\n", shm);

    shm->turn = PA;

	printf("waiting\n");
    shm->n = 2;

    int i;
    for(i = 0; i < shm->n; i++) {
	fgets(shm->words[i], 5, stdin);
    }

    shm->turn = PB;

    while (shm->turn == PB)
	printf("waiting\n");

    shmdt(shm);
    shmctl(shmid, IPC_RMID, 0);

    return 0;
}

