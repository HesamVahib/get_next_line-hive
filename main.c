#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void) {
    int fd;
    char buffer[500];
    int i;

    // Open the file in read mode ("r")
    fd = open("C:\\Users\\hesam\\OneDrive\\Desktop\\getnextline\\content.txt", O_RDONLY);

    // Check if the file was successfully opened
    // i = 0;
    // read(fd, buffer, 70);
    // while (buffer[i] != '\n') {
    //     write(1, &buffer[i], 1);
    //     i++;
    // }
    get_next_line(fd);
    // Close the file
    close(fd);

    return EXIT_SUCCESS;


}