#include "libmx.h"

char *mx_file_to_str(const char *file) {
    int fd = open(file, O_RDONLY);
    if (fd < 0)
        return NULL;
    char buf[2] = {'\0'};
    char *str = NULL;
    char *temp = NULL;
    while(read(fd, &buf, 1)) {
        temp = mx_strjoin(str, buf);
        mx_strdel(&str);
        str = mx_strdup(temp);
        mx_strdel(&temp);
    }
    return str;
}

