#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUF_SIZE 5
int main(int argc, char *argv[])
{

char test[10]={10,234,-23,245,142,65,87,-98,-54,-25};
for(int i=0;i<10;i++){
test[i] =test[i];
}

int otworz;

otworz=open(argv[1],O_WRONLY | O_CREAT | O_TRUNC, 0644);
for(int i=0;i<10;i++){
    write(otworz,test+i,1);
}
 
}

/*
Napisz program, używając niebuforowanych operacji I/O, który wygeneruje 10 pseudo-losowych liczb całkowitych i zapisze je do pliku.
Utwórz drugi program, który odczyta wcześniej zapisane liczby z pliku. Każdą liczbę pomnóż przez 3, a wynik wyświetl na ekranie.
Nazwy plików do zapisu/odczytu użytkownik przekazuje jako argument do wywołania programu.
*/