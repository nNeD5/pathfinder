#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (fd < 0 || buf_size == 0)
        return -2;

    int byte_number = 0;
    char buf[2] = {0};
    char *temp = NULL;
    *lineptr = NULL;

    while(read(fd, &buf, 1)) {
        if (buf[0] == delim) {
            return byte_number;
        }
        temp = mx_strjoin(*lineptr, &buf[0]);
        mx_strdel(lineptr);

        *lineptr = mx_strdup(temp);
        mx_strdel(&temp);
    ++byte_number;
    }
    return -1;
}

