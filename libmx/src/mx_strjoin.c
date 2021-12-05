#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (!s1 && !s2)
        return NULL;

    char *result = NULL;
    int size = 0;

    if (s1 == NULL || s2 == NULL)
        return  s1 ? mx_strdup(s1) : mx_strdup(s2);

    size = mx_strlen(s1) + mx_strlen(s2);
    result = mx_strnew(size);
    mx_strcpy(result, s1);
    mx_strcat(result, s2);

    return result;
}
