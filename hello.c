#include <stdio.h>

int main (int argc, char *argv[])
{
printf("hello world!");

int i;
for(i=0;i<argc;i++)
{
	if(i==0)
{
printf("program name %s\n",argv[i]);
continue;
}

printf("arg %d has value: %s",i,argv[i]);
}


return 0;
}
