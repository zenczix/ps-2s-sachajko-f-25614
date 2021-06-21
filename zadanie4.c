#include <stdio.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char *argv[]){
    DIR *d;
    DIR *dirSystems;
    struct dirent *dir;
    struct dirent *dirSys;
    struct stat file_stat;
    FILE *wp;
    FILE *perms;
    char dirName[256] = "/etc/sysconfig/";
    if(mkdir("results",0777) ==-1)
    {
        perror("error creating directory");
        return 1;
    }
    wp = fopen("results/etc_dir.out","w");
    if(wp == NULL)
    {
        perror("error creating file");
        return 2;
    }

    perms = fopen("results/sysconfig.out","w");
    if(perms == NULL)
    {
        perror("error creating file");
        return 2;
    }


    d = opendir("/etc");
    if(d==NULL){
        perror("/etc");
    }

    dirSystems = opendir("/etc/sysconfig");
    if(dirSystems==NULL){
        perror("/etc/sysconfig");
    }


    while((dir=readdir(d))!= NULL)
    {
        strcpy(dirName,"");
        if(dir->d_type == 4){
            strcpy(dirName,dir->d_name);
            fputs(dirName,wp);
            fputs("\n",wp);
        }
    }

    while((dirSys=readdir(dirSystems))!= NULL)
    {
        strcpy(dirName,"");
        if(dirSys->d_type == 8 ){
            lstat(strcat(dirName,dirSys->d_name),&file_stat);
            if(!(file_stat.st_mode & S_IROTH) && !(file_stat.st_mode & S_IWOTH) && !(file_stat.st_mode & S_IXOTH))
            {
                fputs(dirSys->d_name,perms);
                fputs("\n",perms);
            }
        }
    }
    
    closedir(d);
    fclose(wp);
    fclose(perms);
    return 0;

}