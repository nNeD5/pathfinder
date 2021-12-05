#include "libmx.h"

void mx_del_strarr(char ***arr) {
    if (!arr)
        return;
    char **member = *arr;
    while(*member) {
        mx_strdel(member) ;
        ++member;
    }
    free(*arr);
    *arr = NULL;
}
