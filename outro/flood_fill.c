#include "so_long.h"

void	flood_fill(t_map *map, int x, int y)
{
	if (map->player_x < 0 || map->player_y < 0 || !map->map_cpy[y] || !map->map_cpy[y][x])
		return ;
	if (map->map_cpy[y][x] == '1' || map->map_cpy[y][x] == 'V')
		return ;
	map->map_cpy[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	ft_validate_map_flood_fill(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map_cpy[++i])
	{
		j = 0;
		while (map->map_cpy[i][j])
		{
			if (map->map_cpy[i][j] == '1' || map->map_cpy[i][j] == 'V')
				j++;
			else
				return (1);
		}
	}
	return (0);
}
void ft_fill_cpy(t_map *map)
{
	int i;
	int j;

	i = 0;
	map->map_cpy = malloc((map->height + 1) * sizeof(char *));
	if (!map->map_cpy)
		return (ft_free_map(map), (void)0);
	while(map->map_data[i])
	{
		map->map_cpy[i] = malloc((ft_strlen(map->map_data[i]) + 1) * sizeof(char));
		if (!map->map_cpy[i])
			return (ft_free_map(map), (void)0);
		j = 0;
		while (map->map_data[i][j])
		{
			map->map_cpy[i][j] = map->map_data[i][j];
			j++;
		}
		map->map_cpy[i][j] = '\0';
		i++;
	}
	map->map_cpy[i] = NULL;
}
