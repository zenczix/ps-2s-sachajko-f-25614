#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    pid_t ch_pid;
    FILE *wp;

    int status;
    pid = fork();
    if(pid == -1)
    {
        perror("fork");
        return 1;
    }
    if(pid == 0)
    {
           wp = fopen("numbers.txt","w");
           for(int i=9;i<=99;i++)
           {
               if(i%3==0)
               {
                   fprintf(wp,"%d\n",i);
               }
           }
           fclose(wp);
            _exit(0);

    }
    if(pid>0)
    {
            ch_pid = wait(&status);
            if(WIFEXITED(status))
            {
                 printf("PID (%d) exited normally. Exit status: %d",(int) ch_pid, WEXITSTATUS(status));
            }
    }
    return 0;
}