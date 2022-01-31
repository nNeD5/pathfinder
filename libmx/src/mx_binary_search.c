#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    if (!arr || size <= 0 || !s)
        return -1;

    int left = 0;
    int right = size - 1;
    int index = (left + right) / 2;
    int compare = 0;

    while (left <= right) {
        ++*count;
        compare = mx_strcmp(arr[index], s);
        if (compare == 0)
            return index;
        if (compare > 0)
            right = index - 1;
        if (compare < 0)
            left = index + 1;
        index = (left + right) / 2;
    }
    return -1;
}

int binary_search(char **arr, int size, const char *s, int *count)
{
    unsigned start = 0;
    unsigned end = size - 1;
    unsigned mid = (start + end) / 2;

    while (start <= end) {
        (*count)++;

        if (mx_strcmp(arr[mid], s) == 0)
            return mid;

        else if (mx_strcmp(arr[mid], s) < 0)
            start = mid + 1;

        else
            end = mid - 1;
        mid = (start + end) / 2;
    }
    *count = 0;
    return -1;
}

