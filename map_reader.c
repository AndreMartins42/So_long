/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:31:55 by anmendes          #+#    #+#             */
/*   Updated: 2025/02/01 10:31:55 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_read_map(int fd)
{
	int		i;
	char	*line;
	char	**map;
	size_t	len;

	i = 0;
	fd = open("map_0.ber", O_RDONLY);
	if (fd == -1)
		return (0);
	map = malloc(sizeof(char *) * (ft_count_line(fd) + 1));
	if (map == NULL)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	ft_count_line(int fd)
{
	int		i;
	char	*line;

	i = 0;
	fd = open("map_0.ber", O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
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
			return (1);
		if (map[lines - 1][j] != '1' && map[lines - 1][j] != 'E')
			return (1);
	}
	i = -1;
	while (map[++i])
	{
		if (map[i][0] != '1' && map[i][0] != 'E')
			return (1);
		if (map[i][largura - 1] != '1' && map[i][largura - 1] != 'E')
			return (1);
	}
	return (0);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_validate_char(char c)
{
	if (c == 'P' || c == 'C' || c == 'E' || c == '1' || c == '0')
		return (0);
	return (1);
}
