#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

/*void flood_fill(char **map, int x, int y)
{
    if (x < 0 || y < 0 || !map[y] || !map[y][x])
        return;
    if (map[y][x] == '1' || map[y][x] == 'V')
        return;
    map[y][x] = 'V';
    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);
}*/