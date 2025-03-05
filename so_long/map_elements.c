#include "so_long.h"

int    validate_player_count(t_map	*map)
{
	int	i;
	int	j;

	i = -1;
    map->p = 0;
    map->c = 0;
    map->e = 0;
	map->player_x = 0;
	map->player_y = 0;
	while (map->map_data[++i])
	{
		j = -1;
		while (map->map_data[i][++j])
		{
			if (map->map_data[i][j] == 'P')
			{
				map->p++;
				map->player_y = i;
				map->player_x = j;
			}
            else if (map->map_data[i][j] == 'C')
				map->c++;
            else if (map->map_data[i][j] == 'E')
				map->e++;
		}
	}
	if (map->p == 1 && map->c > 0 && map->e == 1)
		return (0);
	return (1);
}
