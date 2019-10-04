#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>

#define FN "/tmp/my_fifo"

int main(void)
{
    int fd = open(FN, O_RDONLY);

    int i, t;
    for(i = 0; i < 4; i++) {
	read(fd, &t, sizeof(int));
	printf("%d\n", t);
    }

    close(fd);

    remove(FN);

    return 0;
}

