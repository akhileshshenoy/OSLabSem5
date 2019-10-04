#include"header.h"
int main()
{
	int fp=open("temp.txt",O_RDONLY);
	char buf[256];
	read(fp,buf,sizeof(buf));
	int len=strlen(buf);
	int word=1,line=1;
	for(int i=0;i<len;i++)
	{
		if(buf[i]==' ')
			word++;
		if(buf[i]=='\n')
			line++;
	}
	printf("%d %d %d",line,word,len);
}