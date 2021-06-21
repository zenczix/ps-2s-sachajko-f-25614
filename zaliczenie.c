#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/wait.h>

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
        pid = fork();
        if(pid == -1)
        {
            perror("fork");
            return 1;
        }

        if(pid == 0)
        {
            int result = mkdir("zaliczenie/", 0777);
        chmod("zaliczenie/", 0777);

        if(result == -1)
        {
            perror("mkdir");
        }

        char str1[] = "zaliczenie/", *str2 = argv[1];
        FILE *file = fopen(strcat(str1, str2), "w");


        DIR *d;
        struct dirent *dir;
        for(int i = 1; i < argc; i++){
        d = opendir(argv[i]);
        if (d)
        {
            while ((dir = readdir(d)) != NULL){
            if(dir->d_type == 8)
            {
                fprintf(file,"%s\n", dir->d_name);
            } 
            }
        }
        }
        closedir(d);

        }


        if(pid>0)
    {
            ch_pid = wait(&status);
            if(WIFEXITED(status))
            {
                printf("Parent: %d\tPID: %d\tPPID:%d\n",(int) pid, (int) getpid(),(int) getppid());
                printf("PID (%d) exited normally. Exit status: %d",(int) ch_pid, WEXITSTATUS(status));
            }
    }
        return(0);
}