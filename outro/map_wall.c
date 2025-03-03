#include "so_long.h"

int    ft_map_wall(t_map *map)
{
	int	j;
	int	i;

	j = -1;
	while (map->map_data[0][++j])
	{
		if (map->map_data[0][j] != '1')
			return (1);
		if (map->map_data[map->height - 1][j] != '1')
			return (1);
	}
	i = -1;
	while (map->map_data[++i])
	{
		if (map->map_data[i][0] != '1' )
			return (1);
		if (map->map_data[i][map->width - 1] != '1')
			return (1);
	}
	return (0);
}
int ft_map_width(t_map *map)
{
	int i;
	
	i = 0;
	while (map->map_data[i])
	{
		if (ft_strlen(map->map_data[i]) != map->width)
			return (1);
		i++;
	}
	return (0);
}
