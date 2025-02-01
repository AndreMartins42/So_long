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

int	ft_check_map(int fd)
{
	int		i;
	int		largura;
	char	**map;

	fd = open("map_0.ber", O_RDONLY);
	if (fd == -1)
		return (0);
	map = ft_read_map(fd);
	i = 0;
	largura = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != largura)
			return (ft_free_map(map), 1);
		i++;
	}
	if (ft_map_wall(map, fd) == 1)
		return (printf("Mapa invalido wall\n"), ft_free_map(map), 1);
	if (flood_fill_check(map) == 1)
		return (printf("Mapa invalido flood fill\n"), ft_free_map(map), 1);
	return (printf("mapa valido \n"), ft_free_map(map), 0);
}

int	flood_fill_check(char **map)
{
	int	pi;
	int	pj;

	if (validate_map_elements(map) == 1)
		return (1);
	if (validate_elements_counts(map) == 1)
		return (1);
	find_player(map, &pi, &pj);
	flood_fill(map, pi, pj);
	if (ft_validate_map_flood_fill(map) == 1)
		return (1);
	return (0);
}
