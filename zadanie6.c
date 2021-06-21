#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    pid_t ch_pid;
    int r;

    int status;
    pid = fork();
    if(pid == -1)
    {
        perror("fork");
        return 1;
    }
    if(pid == 0)
    {
            sleep(5);
            r = execl("/usr/bin/ls","ls",NULL);
            if(r == -1)
            {
                printf("Error");
            }
            _exit(4);

    }
    if(pid>0)
    {
            sleep(5);
            ch_pid = wait(&status);
            if(WIFEXITED(status))
            {
                 printf("PID (%d) exited normally. Exit status: %d",(int) ch_pid, WEXITSTATUS(status));
            }
    }
    return 0;
}