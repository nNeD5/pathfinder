#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    if (!arr && size <= 0 && !s)
        return -1;

    int left = 0;
    int right = size;
    int index = (left + right) / 2;
    int compare = 0;

    while (left <= right) {
        compare = mx_strcmp(s, arr[index]);
        if (compare == 0)
            return index;
        if (compare > 0)
            left = index + 1;
        if (compare < 0) {
            right = index - 1;
        }
        ++*count;
        index = (left + right) / 2;
    }
    return -1;
}
