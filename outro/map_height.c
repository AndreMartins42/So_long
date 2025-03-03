#include "so_long.h"

void map_height(t_map *map, char *file_path)
{
    int fd;
    char *line;

    fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return ;
    map->height = 0;
    line = get_next_line(fd);
    while (line)
    {
        map->height++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}
