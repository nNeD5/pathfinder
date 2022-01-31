#include "pathfinder.h"

void check_empty_file(int rd, char *argv[]) {
    if (rd == -1) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(1);
    }
}

void check_first_line(char *line) {
    while (mx_isdigit(*line))
        line++;
    if (*line == '\0')
        return;
    mx_printerr("error: line 1 is not valid\n");
    exit(1);
}

void check_isl_num(t_map *map) {
    if (map->iNum != map->stated_iNum) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
}

void check_bridge_len(t_map *map) {
    if (map->total_len > INT_MAX) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(1);
    }
}

void check_line(char *line, unsigned int count) {
    while (mx_isalpha(*line))
        line++;
    if (*(line++) == '-') {
        while (mx_isalpha(*line))
            line++;
        if (*(line++) == ',') {
            while (mx_isdigit(*line))
                line++;
            if (*line == '\0')
                return;
        }
    }
    error_inline(count);
}

