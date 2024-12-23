#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void) {
    int fd;
    char *buffer;
    int i = 1;
    fd = open("the_text.txt", O_RDONLY);
    //fd = STDIN_FILENO;
    while ((buffer = get_next_line(fd)) != NULL) {
        printf("[%d]%s", i, buffer);
        i++;
        free(buffer);
    }

    close(fd);
    return EXIT_SUCCESS;
}
