/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:03:16 by marvin            #+#    #+#             */
/*   Updated: 2025/02/03 20:10:52 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#define WIDTH 600
#define HEIGHT 800

# include "./minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

char	*get_next_line(int fd);
char	*read_file(int fd, char *cache);
char	*ft_line(char *buffer);
char	*ft_next(char *buffer);
int		ft_strlcpy(char *dst, char *src, int size);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
int		ft_strlen(char *str);
int		ft_check_map(int fd);
int		flood_fill_check(char **map);
void	flood_fill(char **map, int x, int y);
int		ft_validate_map_flood_fill(char **map);
void	find_player(char **map, int *pi, int *pj);
char	**ft_read_map(int fd);
int		ft_count_line(int fd);
int		ft_map_wall(char **map, int fd);
void	ft_free_map(char **map);
int		ft_validate_char(char c);
int		validate_map_elements(char **map);
int		validate_elements_counts(char **map);
int		validate_player_count(char **map);
int		validate_coins_count(char **map);
int		validate_exit_count(char **map);
int		mouse(t_vars *data);
int		keyboard(int keysym, t_vars *data);



#endif
