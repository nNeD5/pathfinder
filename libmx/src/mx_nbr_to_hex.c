#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    char *hex = NULL;
    int base = 16;
    int length = 0;
    int rem = 0;

    for (int number = nbr; number > 0; ++length) {
        number /= base;
    }

    hex = mx_strnew(length);
    if (!hex)
        return NULL;

    for (; length > 0;  --length) {
        rem = nbr % base;
        nbr /= base;

        if (rem >= 10)
            hex[length - 1] = (rem + 87);
        else
            hex[length - 1] = (rem + 48);
    }
    return hex;
}
