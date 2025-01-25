/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:03:16 by marvin            #+#    #+#             */
/*   Updated: 2025/01/25 15:40:00 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*read_file(int fd, char *cache);
char	*ft_line(char *buffer);
char	*ft_next(char *buffer);
int		ft_strlcpy(char *dst, char *src, int size);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
int		ft_strlen(char *str);



char **ft_fill(int fd);
int ft_count_line(int fd);
int ft_map_wall(char **map, int fd);
int ft_validate_flood(char **map);
void ft_free_map(char **map);
void flood_fill(char **map, int x, int y);
int ft_validate_map(char **map);

#endif