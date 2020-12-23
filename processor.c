#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

double c_to_f(double c){
    double f;
    f = (c * 9/5) + 32;
    return f;
}

int main(){
    
    //file 1
    mkfifo("input", 0666);
    mkfifo("output", 0666);

    int fd; 
    double celsius, fahrenheit; 
    while (1){
        //gets input from console
        fd = open("input", O_RDONLY);
        read(fd, &celsius, sizeof(celsius));
        close(fd);

        //sends response to console
        fahrenheit = c_to_f(celsius);
        fd = open("output", O_WRONLY);
        write(fd, &fahrenheit, sizeof(fahrenheit));
        close(fd);
    }
    
    return 0;
}
