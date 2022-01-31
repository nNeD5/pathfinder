#include "../inc/libmx.h"

static void swap(int *x, int *y, int *count)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
    ++*count;
}

int mx_quicksort(int *arr, int left, int right) {
    if (left >= right || !arr)
        return -1;

    int counter = 0, i = left, j = right - 1, pivot = arr[right];

    while (i < j) {
        while (arr[i] <= pivot && i < right) { i++; }
        while (arr[j] > pivot) { --j; }
        if (i > j)
            break;
        swap(&arr[i++], &arr[j--], &counter);
    }

    if (arr[i] > pivot)
        swap(&arr[i], &arr[right], &counter);
    if ((int)j > left)
        counter += mx_quicksort(arr, left, j);
    if ((int)i + 1 < right)
        counter += mx_quicksort(arr, i + 1, right);

    return counter;
}

