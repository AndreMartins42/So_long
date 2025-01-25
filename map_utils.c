#include "get_next_line.h"

int ft_validate_flood(char **map)
{
    int i;
    int p;
    int j;
    int c;
    int e;

    i = 0;
    p = 0;
    c = 0;
    e = 0;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
                p++;
            else if(map[i][j] == 'C')
                c++;
            else if(map[i][j] == 'E')
                e++;
            j++;
        }
        i++;
    }
    if (p == 1 && c > 0 && e == 1)
    {
        flood_fill(map, j, i);
        flood_fill_check(map)
    }
    ft_free_map(map)
}

int flood_fill_check(int p, int c, int e, char **map)
{
    int i;
    int j;
    
    i = 0;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
            {
                flood_fill(map, i, j);
                return (ft_validate_map(map));
            }
        }
    }

}

int ft_count_line(int fd)
{
    int i;
    char *line;

    i = 0;
    fd = open("map_0.ber", O_RDONLY);
    if (fd == -1)
        return (0);
    while ((line = get_next_line(fd)) != NULL )
	{
		i++;
		free(line);
	}
    close(fd);
    return (i);
}

char **ft_fill(int fd)
{
    int i = 0;
    char *line;
    char **map;
    size_t len;

    fd = open("map_0.ber", O_RDONLY);
    if(fd == -1)
        return (0);
    map = malloc(sizeof(char *) * (ft_count_line(fd) + 1));
    if(map == NULL)
        return (0);
    while ((line = get_next_line(fd)) != NULL)
	{
        len = ft_strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';
		map[i] = line;
		i++;
	}
	map[i] = NULL;
    close(fd);
    return (map);
}

void ft_free_map(char **map)
{
    int i = 0;

    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}
/* void print_map(char **map)
{
    int i = 0;
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
} */

/*     if (p == 1 && c > 0 && e == 1)
    {
        flood_fill(map, pj, pi);
        if (ft_validate_map(map) == 0)
            return (ft_free_map(map), 0);
    } */