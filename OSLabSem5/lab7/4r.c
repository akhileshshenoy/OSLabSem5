#include <stdio.h>

#include <sys/shm.h>
#include <sys/types.h>

#include <unistd.h>

#define PA 1
#define PB 2

struct s {
    int turn;
    int n;
    char words[8][80];
} *shm;

int main(void)
{
    int shmid = shmget((key_t) 1234, sizeof(struct s), 0666 | IPC_CREAT);
    shm = (struct s *) shmat(shmid, (void *) 0, 0);

    while (shm->turn == PA);

    int i;
    for(i = 0; i < shm->n; i++) {
	puts(shm->words[i]);
	shm->words[i] = NULL;
    }

    shm->turn = PA;

    shmdt(shm);

    return 0;
}

