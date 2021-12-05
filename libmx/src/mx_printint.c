#include <libmx.h>

void mx_printint(int n) {
    int number_of_digits = 0;
    int temp = n;

    if (n < 0)
        mx_printchar('-');

    do {
        temp /= 10;
        number_of_digits++;
    } while (temp != 0);

    char str[number_of_digits];
    for (int i = 0; i < number_of_digits; i++) {
        temp = n % 10;
        str[i] = n > 0 ?  temp + '0' : -temp + '0';
        n /= 10;
    }

    for (int i = number_of_digits - 1; i >= 0;  i--) {
        mx_printchar(str[i]);
    }
}
