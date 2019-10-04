#include"header.h"
int main()
{
	char dirname[10];
	DIR *p;
	struct dirent *d;
	printf("Enter directory name:\n");
	scanf("%s",dirname);
	p=opendir(dirname);
	if(p==NULL)
	{
		printf("Cannot find directory\n");
		exit(-1);
	}
	while(d=readdir(p))
		printf("%s\n",d->d_name);
}