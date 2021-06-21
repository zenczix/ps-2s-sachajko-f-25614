#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{


struct stat file_stat;
char *file_type;
char perm[]="---------";
for(int i=1;i<argc;i++)
{

if(lstat(argv[i],&file_stat)==-1)
{
    perror(argv[i]);
    continue;
}
printf("%s",argv[i]);
printf("\tSize: %ld\n", file_stat.st_size);
if((file_stat.st_mode & S_IFMT)==S_IFDIR)
{
    file_type="directory";

}else
{
    file_type="** other **";
}

printf("\tType: %s\n",file_type);

if(file_stat.st_mode & S_IRUSR)perm[0]='r';
if(file_stat.st_mode & S_IRUSR)perm[1]='w';
if(file_stat.st_mode & S_IRUSR)perm[2]='x';
if(file_stat.st_mode & S_IRUSR)perm[3]='r';
if(file_stat.st_mode & S_IRUSR)perm[4]='w';
if(file_stat.st_mode & S_IRUSR)perm[5]='x';
if(file_stat.st_mode & S_IRUSR)perm[6]='r';
if(file_stat.st_mode & S_IRUSR)perm[7]='w';
if(file_stat.st_mode & S_IRUSR)perm[8]='x';


  printf("%s : ",argv[i]);
        printf("\tSize: %ld\n",file_stat.st_size);
        printf("\t Type: %s \n",file_type);
printf("\tPermissions: %s\n",perm);
strcpy(perm,"---------");
}


return 0;
}