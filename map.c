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

#include "so_long.h"

int	ft_check_map(char *file_path)
{
	int		i;
	int		fd;
	int		largura;
	t_map	*map;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	map = malloc(sizeof(t_map));
	map->map_data = ft_read_map(fd, file_path);
	i = 0;
	largura = ft_strlen(map->map_data[0]);
	while (map->map_data[i])
	{
		if (ft_strlen(map->map_data[i]) != largura)
			return (ft_free_map(map), 1);
		i++;
	}
	if (ft_map_wall(map, fd, file_path) == 1)
		return (printf("Mapa invalido wall\n"), ft_free_map(map), 1);
	if (flood_fill_check(map) == 1)
		return (printf("Mapa invalido flood fill\n"), ft_free_map(map), 1);
	return (printf("mapa valido \n"), ft_free_map(map), 0);
}

int	flood_fill_check(t_map *map)
{
	t_player	*player;

	if (validate_map_elements(map) == 1)
		return (1);
	if (validate_elements_counts(map) == 1)
		return (1);
	find_player(map, player);
	flood_fill(map, player->x, player->y);
	if (ft_validate_map_flood_fill(map) == 1)
		return (1);
	return (0);
}
