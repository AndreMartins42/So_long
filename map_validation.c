/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:30:04 by anmendes          #+#    #+#             */
/*   Updated: 2025/02/01 10:30:04 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_player_count(t_map	*map)
{
	int	i;
	int	j;
	int	p;

	i = -1;
	p = 0;
	while (map->map_data[++i])
	{
		j = -1;
		while (map->map_data[i][++j])
		{
			if (map->map_data[i][j] == 'P')
				p++;
		}
	}
	return (p);
}

int	validate_coins_count(t_map *map)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	c = 0;
	while (map->map_data[++i])
	{
		j = -1;
		while (map->map_data[i][++j])
		{
			if (map->map_data[i][j] == 'C')
				c++;
		}
	}
	return (c);
}

int	validate_exit_count(t_map *map)
{
	int	i;
	int	j;
	int	e;

	i = -1;
	e = 0;
	while (map->map_data[++i])
	{
		j = -1;
		while (map->map_data[i][++j])
		{
			if (map->map_data[i][j] == 'E')
				e++;
		}
	}
	return (e);
}

int	validate_map_elements(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map_data[++i])
	{
		j = -1;
		while (map->map_data[i][++j])
		{
			if (ft_validate_char(map->map_data[i][j]) == 1)
				return (1);
		}
	}
	return (0);
}

int	validate_elements_counts(t_map *map)
{
	int	p;
	int	e;
	int	c;

	p = validate_player_count(map);
	c = validate_coins_count(map);
	e = validate_exit_count(map);
	if (p == 1 && e == 1 && c > 0)
		return (0);
	return (1);
}
