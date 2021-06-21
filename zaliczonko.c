#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
/*
Nazwa pliku, który będzie przechowywał wyniki działania programu, zostanie przekazana przez użytkownika jako parametr do wywołania programu.
Jako drugi oraz kolejne argumenty będą przekazywane nazwy (ścieżki) folderów, z których należy wylistować tylko pliki regularne. 
Za pomocą operacji buforowanych, nazwy plików będę zapisane do pliku (nazwa przekazana w pierwszym argumencie), który będzie umieszczony w katalogu zaliczenie
Program stworzy nowy katalog zaliczenie, z uprawnieniami 0777
Powyższe operacje (tworzenie nowego katalogu, tworzenie pliku) odbywają się w procesie potomnym
Proces rodzica czeka na zakończenie procesu potomnego.
Przed zakończeniem programu wyświetl informację o numerze PID rodzica, dziecka, oraz to że program się zakończył. */

int main(int argc, char *argv[])
{
pid_t pid;
pid_t ch_pid;
int status;
FILE *wp;
DIR *d;
struct dirent *dir;
char buf[100];
char fileName[100]="zaliczenie/";

pid=fork();

if(pid==-1){
    perror("fork");
    return 1;
}

if(pid==0){
    if(mkdir("zaliczenie",0777)==-1){
    perror("error while creating directory");
    return 1;
}

wp=fopen(strcat(fileName,argv[1]),"w");
if(wp==NULL){
    perror("error creating file");
    return 1;
}

for(int i=2;i<argc;i++){
    if(dir->d_type==0){
        snprintf(buf,sizeof(buf),"\t%s\n",dir->d_name);
        fprintf(wp,buf);
    }
    
}
closedir(d);
}
fclose(wp);
_exit(0);




}