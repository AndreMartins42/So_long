/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:29:16 by anmendes          #+#    #+#             */
/*   Updated: 2025/01/25 14:29:16 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int	ft_check_map(int fd)
{
	int		i;
	int		lines;
	int		largura;
	char	**map;

	fd = open("map_0.ber", O_RDONLY);
	if (fd == -1)
		return (0);
	map = ft_fill(fd);
	i = 0;
	lines = ft_count_line(fd);
	largura = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != largura)
			return (ft_free_map(map), 1);
		i++;
	}
	if (ft_map_wall(map, fd) == 1)
		return (printf("Mapa invalido\n"), 1);
	if (ft_validate_flood(map) == 1)
		return (printf("Mapa invalido\n"), 1);
	return (printf("mapa valido \n"), 0);
}

int	ft_map_wall(char **map, int fd)
{
	int	j;
	int	i;
	int	lines;
	int	largura;

	lines = ft_count_line(fd);
	largura = ft_strlen(map[0]);
	j = -1;
	while (map[0][++j])
	{
		if (map[0][j] != '1' && map[0][j] != 'E')
			return (printf("Parede superior invalida\n"), ft_free_map(map), 1);
		if (map[lines - 1][j] != '1' && map[lines - 1][j] != 'E')
			return (printf("Parede inferior invalida\n"), ft_free_map(map), 1);
	}
	i = -1;
	while (map[++i])
	{
		if (map[i][0] != '1' && map[i][0] != 'E')
			return (printf("Parede esquerda invalida\n"), ft_free_map(map), 1);
		if (map[i][largura - 1] != '1' && map[i][largura - 1] != 'E')
			return (printf("Parede direita invalida\n"), ft_free_map(map), 1);
	}
	return (0);
}

void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x])
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	ft_validate_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != 'V')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
