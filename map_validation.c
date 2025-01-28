#include "so_long.h"

int validate_player_count(char **map)
{
    int i;
    int j;
    int p;

    i = -1;
    p = 0;
    while(map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (map[i][j] == 'P')
                p++;
        }
    }
    return (p);
}

int validate_coins_count(char **map)
{
    int i;
    int j;
    int c;

    i = -1;
    c = 0;
    while(map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (map[i][j] == 'C')
                c++;
        }
    }
    return (c);
}
int validate_exit_count(char **map)
{
    int i;
    int j;
    int e;

    i = -1;
    e = 0;
    while(map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (map[i][j] == 'E')
                e++;
        }
    }
    return (e);
}
int validate_map_elements(char **map)
{
    int i;
    int j;

    i = -1;
    while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (ft_validate_char(map[i][j]) == 1)
                return (1);

        }
    }
    return (0);
}

int validate_elements_counts(char **map)
{
    int p;
    int e;
    int c;

    p = validate_player_count(map);
    c = validate_coins_count(map);
    e = validate_exit_count(map);
    if (p == 1 && e == 1 && c > 0)
        return (0);
    return (1);
}
