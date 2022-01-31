#include "pathfinder.h"

static void init_map(t_map **map, unsigned int isle_num) {
    *map = malloc(sizeof (t_map));
    (*map)->iNum = 0;
    (*map)->total_len = 0;
    (*map)->stated_iNum = isle_num;
    (*map)->iArr = malloc(sizeof(char *) * isle_num);
    (*map)->bx = (bool **)malloc(sizeof(bool *) * isle_num);
    (*map)->mx = (unsigned int **)malloc(sizeof(int *) * isle_num);
    for (unsigned int i = 0; i < isle_num; ++i) {
        (*map)->iArr[i] = NULL;
        (*map)->bx[i] = (bool *)malloc(sizeof(bool) * isle_num);
        (*map)->mx[i] = (unsigned int *)malloc(sizeof(int) * isle_num);
        for (unsigned int j = 0; j < isle_num; ++j) {
            if (i == j) {
                (*map)->mx[i][j] = 0;
                (*map)->bx[i][j] = true;
            } else {
                (*map)->bx[i][j] = false;
                (*map)->mx[i][j] = INT_MAX;
            }
        }
    }
}

static void add_bridge(t_map *map, unsigned int a, unsigned int b,
                        unsigned int len) {
    if (map->bx[a][b])
            error_dupbridges();
    map->mx[a][b] = len;
    map->mx[b][a] = len;
    map->bx[a][b] = true;
    map->bx[b][a] = true;
    map->total_len += len;
}

static unsigned int add_isl(t_map *map, char *name) {
    int i;

    for (i = 0; map->iArr[i] != NULL; ++i)
        if (!mx_strcmp(map->iArr[i], name))
            return i;
    map->iNum++;
    if (map->iNum > map->stated_iNum) {
        error_isl_num();
    }
    map->iArr[i] = mx_strdup(name);
    return i;
}

static void parse_line(t_map *map, char *line, unsigned int count) {
    if(*line == '\0')
        return;
    check_line(line, count);

    unsigned int a, b;
    unsigned long len;
    char *temp = mx_strchr(line, '-');

    *temp = '\0';
    ++temp;
    a = add_isl(map, line);

    line = temp;
    temp = mx_strchr(temp, ',');
    *temp = '\0';
    b = add_isl(map, line);
    ++temp;
    len = mx_atol(temp);
    if (a == b) {
        error_inline(count);
    }

    add_bridge(map, a, b, len);
    return;
}

void form_map(t_map **map, int fd, char *argv[]) {
    char *line = NULL;
    int rd = mx_read_line(&line, 10, '\n', fd);
    int bridge_number = 0;

    check_empty_file(rd, argv);
    check_first_line(line);
    bridge_number = mx_atoi(line);
    init_map(map, bridge_number);
    rd = mx_read_line(&line, 10, '\n', fd);
    for (int i = 2; rd != -1; ++i) {
        if ((i - 1) > bridge_number)
            error_isl_num();
        parse_line(*map, line, i);
        rd = mx_read_line(&line, 10, '\n', fd);
        // if ((last_line && rd != -1) || (!last_line && rd == -1)) {
        //     error_inline(i);
        // }
    }
    check_isl_num(*map);
    check_bridge_len(*map);
    free(line);
}

