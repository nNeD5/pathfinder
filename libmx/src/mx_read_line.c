#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (fd < 0)
        return -2;

    static int byte_number = 0;
    char buf[buf_size + 1];
    char *temp = NULL;

    while(read(fd, &buf, buf_size)) {
        if (buf[buf_size] == delim)
            return byte_number;
        ++byte_number;
        temp = mx_strjoin(*lineptr, buf);
        mx_strdel(lineptr);

        *lineptr = mx_strdup(temp);
        mx_strdel(&temp);
        //printf("%s\n", *lineptr);
    }
    return byte_number;
}
