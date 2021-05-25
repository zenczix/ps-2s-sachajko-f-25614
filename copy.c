#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]){

    int input_fd, output_fd;
    char buffer[BUF_SIZE];
    ssize_t ret_in, ret_out;

    if(argc != 3 || strcmp(argv[1], "--help") == 0){
        printf("Usaeg: %s file_origin file_destination\n", argv[0]);
        return 1;
    }

    input_fd = open(argv[1], O_RDONLY);

    if(input_fd == -1){
        perror(argv[1]);
        return 2;
    }

    output_fd = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if(output_fd == -1){
        perror(argv[2]);
        return 3;
    }

    while((ret_in = read(input_fd, &buffer, BUF_SIZE)) > 0){
        
        ret_out = write(output_fd, &buffer, BUF_SIZE);

        if(ret_out != ret_in){
            fprintf(stderr,"Error while writing\n");
            return 4;
        }
    }

    close(input_fd);
    close(output_fd);
}