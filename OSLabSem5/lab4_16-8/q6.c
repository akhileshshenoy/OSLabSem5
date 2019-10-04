#include"header.h"
int main()
{
	int fp=open("temp.txt",O_RDONLY);
	int fd=open("temp2.txt",O_WRONLY);
	char buf[256];
	read(fp,buf,sizeof(buf));
	write(fd,buf,strlen(buf));
}