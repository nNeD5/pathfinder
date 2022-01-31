#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *rslt = NULL;

    if ((int)size == 0 && ptr) {
        free(ptr);
        return NULL;
    }
    if (!ptr) return malloc(size);

    rslt = malloc(size);
    mx_memcpy(rslt, ptr, size);
    free(ptr);
    return rslt;
}

