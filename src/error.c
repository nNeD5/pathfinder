#include "pathfinder.h"

void error_inline(unsigned int line_num) {
    char *err = mx_itoa(line_num);

    mx_printerr("error: line ");
    mx_printerr(err);
    mx_printerr(" is not valid\n");
    free(err);
    exit(1);
}

void error_dupbridges() {
    mx_printerr("error: duplicate bridges\n");
    exit(1);
}

void error_isl_num() {
    mx_printerr("error: invalid number of islands\n");
    exit(1);
}

