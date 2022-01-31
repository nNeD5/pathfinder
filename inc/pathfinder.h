#pragma once

#include "libmx.h"

// #define INT_MAX 2147483647

typedef struct s_map {
    char **iArr;
    unsigned int **mx;
    bool **bx;
    unsigned int iNum;
    unsigned int stated_iNum;
    unsigned long total_len;
}               t_map;


// Error calling functions
void error_inline(unsigned int line_num);
void error_dupbridges();
void error_isl_num();
// Error checking functions
void check_empty_file(int rd, char *argv[]);
void check_first_line(char *line);
void check_isl_num(t_map *map);
void check_bridge_len(t_map *map);
void check_line(char *line, unsigned int count);
// File parsing function
void form_map(t_map **map, int fd, char *argv[]);
// Pathfinding function (using Floyd-Warshall algorithm)
void build_mtx(t_map *map);

