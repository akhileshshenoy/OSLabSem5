#include <unistd.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/shm.h>

#define PA 1
#define PB 2

struct s{
    int turn;
    char c;
} *shd;

void *shm;

void child()
{
    while (shd->turn == PA);

    shd->c += 1;

    shd->turn = PA;
}

void parent()
{
    if (shd->turn == PA) {
	shd->c = 'A';
	shd->turn = PB;
    }
    
    while (shd->turn == PB);

    printf("%c\n", shd->c);
}

int main(void)
{
    int shmid = shmget((key_t) 1234, sizeof(struct s), 0666 | IPC_CREAT);

    if (shmid == -1) {
	printf("shmget\n");
	return 0;
    }

    shm = shmat(shmid, (void *) 0, 0);

    shd = (struct s *) shm;

    shd->turn = PA;

    if (fork())
	child();
    else
	parent();

    shmdt(shm);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

