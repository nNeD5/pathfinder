#include "libmx.h"

int mx_quicksort(int *arr, int left, int right) {
    static int counter = 0;

    if (left >= right)
        return counter;

    int i = left, j = right, x = arr[right];

    while (i <= j) {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if(i <= j) {
            if (i != j && arr[i] != arr[j]) {
                mx_swap_int(arr + i, arr + j);
                ++counter;
            }
            i++;
            j--;
        }
    }

    mx_quicksort(arr, left, j);
    mx_quicksort(arr, i, right);

    return counter;
}

