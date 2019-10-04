#include <stdio.h>
#include <sys/msg.h>

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

    scanf("%d", &msg.n);

    int res = msgsnd(qid, (void *) &msg, sizeof(msg.n), 0);

    if (res == -1) {
	printf("msgsnd\n");
	return 0;
    }

    return 0;
}

