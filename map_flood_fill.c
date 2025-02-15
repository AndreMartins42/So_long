/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:37:44 by anmendes          #+#    #+#             */
/*   Updated: 2025/02/01 10:37:44 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || !map->map_data[y] || !map->map_data[y][x])
		return ;
	if (map->map_data[y][x] == '1' || map->map_data[y][x] == 'V')
		return ;
	map->map_data[y][x] = 'V';
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
	while (map->map_data[++i])
	{
		j = -1;
		while (map->map_data[i][++j])
		{
			if (map->map_data[i][j] == '1' || map->map_data[i][j] == 'V')
				j++;
			else
				return (1);
		}
	}
	return (0);
}

void	find_player(t_map *map, t_player *player)
{
	int	y;
	int	x;

	y = 0;
	while (map->map_data[y])
	{
		x = 0;
		while (map->map_data[y][x])
		{
			if (map->map_data[y][x] == 'P')
			{
				player->y = y;
				player->x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}
