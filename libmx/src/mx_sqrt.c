#include "libmx.h"

int mx_sqrt(int x) {
    for (int i = 1; i <= x / 2; ++i) {
        if (mx_pow(i, 2) == x)
            return i;
    }
    return 0;
}
