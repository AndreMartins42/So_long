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

char	**ft_read_map(int fd, char *file_path)
{
	int		i;
	char	*line;
	t_map	*map;
	size_t	len;

	i = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	map = malloc(sizeof(t_map));
	map->map_data = malloc(sizeof(char *) * (ft_count_line(fd, file_path) + 1));
	if (!map->map_data)
		return (close(fd), NULL);
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		map->map_data[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map->map_data[i] = NULL;
	close(fd);
	return (map->map_data);
}

int	ft_count_line(int fd, char *file_path)
{
	int		i;
	char	*line;

	i = 0;
	fd = open(file_path, O_RDONLY);
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

int	ft_map_wall(t_map *map, int fd, char *file_path)
{
	int	j;
	int	i;
	int	lines;
	int	largura;

	lines = ft_count_line(fd, file_path);
	largura = ft_strlen(map->map_data[0]);
	j = -1;
	while (map->map_data[0][++j])
	{
		if (map->map_data[0][j] != '1' && map->map_data[0][j] != 'E')
			return (1);
		if (map->map_data[lines - 1][j] != '1' && map->map_data[lines - 1][j] != 'E')
			return (1);
	}
	i = -1;
	while (map->map_data[++i])
	{
		if (map->map_data[i][0] != '1' && map->map_data[i][0] != 'E')
			return (1);
		if (map->map_data[i][largura - 1] != '1' && map->map_data[i][largura - 1] != 'E')
			return (1);
	}
	return (0);
}

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_data[i])
	{
		free(map->map_data[i]);
		i++;
	}
	free(map->map_data);
}

int	ft_validate_char(char c)
{
	if (c == 'P' || c == 'C' || c == 'E' || c == '1' || c == '0')
		return (0);
	return (1);
}
