#include"header.h"
int main()
{
	int fp=creat("temp.txt",S_IRWXU);
	char buf[256];
	printf("Enter string:\n");
	gets(buf);
	write(fp,buf,strlen(buf));
}