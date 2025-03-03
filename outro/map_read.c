#include "so_long.h"

int	ft_read_map(t_map *map, char *file_path)
{
	int		i;
    int fd;
	char	*line;
	size_t	len;

    fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (1);
	map->map_data = malloc((map->height + 1) * (sizeof(char *)));
	if (!map->map_data)
		return (ft_free_map(map), 1);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		map->map_data[i] = line;
		//printf("Linha %d: %s\n", i, line); 
		line = get_next_line(fd);
		i++;
	}
	map->map_data[i] = NULL;
	map->width = ft_strlen(map->map_data[0]);
	return (close(fd), 0);
}
int	ft_validate_char(char c)
{
	if (c == 'P' || c == 'C' || c == 'E' || c == '1' || c == '0')
		return (0);
	return (1);
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