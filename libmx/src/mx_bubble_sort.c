#include "libmx.h"

int mx_bubble_sort(int *arr, int size) {
    int n = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (arr[i] > arr[j]) {
                ++n;
                mx_swap_int(&arr[i], &arr[j]);
            }
        }
    }
    return n;
}
