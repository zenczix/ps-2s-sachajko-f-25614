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
printf("changing mode of a file: count.exe")
if(stat("count.exe",&file_stat)==-1)
{
    perror("count.exe");
    return 1;
}
if(chmod("count.exe",(file_stat.st_mode | S_IXOTH))==-1)
{
    perror("count.exe");
    return 2;
}

return 0;
}