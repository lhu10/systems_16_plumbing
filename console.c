#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){

    //file 0
    int fd; 
    double celsius, fahrenheit; 
    printf("Converts Temperature in Celsius to Fahrenheit\n");
    while (1){
        printf("Temp in Celsius: ");
        scanf("%lf", &celsius);

        //sends input to processor
        fd = open("input", O_WRONLY);
        write(fd, &celsius, sizeof(celsius));
        close(fd);

        //reads and displays response
        fd = open("output", O_RDONLY);
        read(fd, &fahrenheit, sizeof(fahrenheit));
        printf("Temp in Fahrenheit: %lf\n", fahrenheit);
        close(fd);
    }

    return 0;
}
