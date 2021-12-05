#include "libmx.h"

char *mx_itoa(int number) {
    char sign = number > 0 ? '+' : '-';
    int lenght = number  > 0 ? 0 : 1;
    char *str = NULL;
    int rem = 0;
    int base = 10;
    number = mx_mod(number);

    for (int nbr = number; nbr > 0; ++lenght)
        nbr /= base;

    str = mx_strnew(lenght);
    if (!str)
        return NULL;

    for (int i  = --lenght; i >= (sign == '+' ? 0 : 1); --i) {
        rem = number % base;
        number /= base;
        str[i] = (rem + 48);
    }

    if (sign == '-')
        str[0] = sign;
    return str;
}
