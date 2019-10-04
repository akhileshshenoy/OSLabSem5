#include <stdio.h>
#include <sys/msg.h>

int pal(int n)
{
    int t = n, r = 0;

    while (t) {
	r = r * 10 + t % 10;
	t /= 10;
    }

    return r==n;
}

int main()
{
    struct {
	long int msg_t;
	int n;
    } msg;

    int qid = msgget((key_t) 1234, 0666 | IPC_CREAT);

    if (qid == -1) {
	printf("msgget\n");
	return 0;
    }

    int res = msgrcv(qid, (void *) &msg, sizeof(msg.n), (long int) 0, 0);

    if (res == -1) {
	printf("msgrcv\n");
	return 0;
    }

    res = msgctl(qid, IPC_RMID, NULL);

    printf("%d\n", pal(msg.n));

    return 0;
}

