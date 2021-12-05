#ifndef PATHFINDER_HEADER
#define PATHFINDER_HEADER


#include "libmx.h"

typedef struct s_graph {
    int vertex_number;
    int **mtx; /* size must be [vertex_number][vertex_number] */
}              t_graph;


#endif
