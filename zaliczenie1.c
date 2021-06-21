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
int wynik=mkdir("zaliczenie/",0777);
char fileName[150]="zaliczenie/";
chmod("zaliczenie/",0777);

if(wynik==-1 ){
    perror("error while creating directory");
    return 1;
}
FILE* file= fopen(strcat(fileName,*argv[]),"w");

DIR *d;
struct dirent *dir;
for(int i=1;i<argc;i++)
{
s=opendir(argv[i]);
if(s)
{
    while((dir=readdir(s))!=NULL){
        if(dir->d_type==8){
            fprintf(file,"%s\n",dir->d_name);
        }
    }
}

}
closedir(s);
return 0;
}