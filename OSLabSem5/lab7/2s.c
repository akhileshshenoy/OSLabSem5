#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>

#define FN "/tmp/my_fifo"

int main(void)
{
    int data[] = {1, 2, 3, 4};

    int res = mkfifo(FN, 0666);    

    if (res == -1) {
	printf("mkfifo\n");
	return 0;
    }

    int fd = open(FN, O_WRONLY);

    int i;
    for(i = 0; i < 4; i++)
	res = write(fd, &data[i], sizeof(int));

    close(fd);

    return 0;
}

