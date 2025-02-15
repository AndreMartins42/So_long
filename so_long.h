/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:03:16 by marvin            #+#    #+#             */
/*   Updated: 2025/02/15 17:48:46 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
//# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


typedef struct s_map 
{   
    char    **map_data;
    int     width;
    int     height;
}   t_map;

typedef struct s_player
{
    int x;
    int y;
}   t_player;

typedef struct s_window {
    void    *mlx;    
    void    *win;
    int     width; 
    int     height;
}   t_window;

typedef struct s_imgs
{
    void    *player_img;    
    void    *exit_img;    
    void    *collect_img;    
    void    *floor_img;    
    void    *wall_img;   
}   t_imgs;

typedef struct s_game 
{
    t_window    *window;
    t_map       *map;
    t_player    *player;
    t_imgs      *imgs;
}   t_game;


/* typedef struct s_img_x { 
    void *player;//P
    void *collect;//C
    void *exit; //E
    void *floor; //0
    void *wall;
    void *image;    
    int width; 
    int height; 
} t_img_x;
 */

char	*get_next_line(int fd);
char	*read_file(int fd, char *cache);
char	*ft_line(char *buffer);
char	*ft_next(char *buffer);
int		ft_strlcpy(char *dst, char *src, int size);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
int		ft_strlen(char *str);
int     ft_check_map(char *file_path);
int		flood_fill_check(t_map *map);
void	flood_fill(t_map *map, int x, int y);
int		ft_validate_map_flood_fill(t_map *map);
void	find_player(t_map *map, t_player *player);
char	**ft_read_map(int fd, char *file_path);
int	ft_count_line(int fd, char *file_path);
int	ft_map_wall(t_map *map, int fd, char *file_path);
void	ft_free_map(t_map *map);
int		ft_validate_char(char c);
int		validate_map_elements(t_map *map);
int		validate_elements_counts(t_map *map);
int		validate_player_count(t_map *map);
int		validate_coins_count(t_map *map);
int		validate_exit_count(t_map *map);
int		mouse(t_game *game);
int     keyboard(int keysym, t_game *game);
void    render_map(t_game *game);
t_game *init_game(void);



#endif
