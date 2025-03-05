#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


typedef struct s_map 
{   
    char    **map_data;
    char    **map_cpy;
    int     width;
    int     height;
    int     p;
    int     c;
    int     e;
    int     player_x;
    int     player_y;
}   t_map;

typedef struct s_window 
{
    void    *mlx;    
    void    *win;
    int     width; 
    int     height;
    t_map   *map;
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
    t_imgs      *imgs;
    int         count;
}   t_game;


char    *get_next_line(int fd);
char    *read_file(int fd, char *cache);
char    *ft_line(char *buffer);
char    *ft_next(char *buffer);
int     ft_strlcpy(char *dst, char *src, int size);
char    *ft_strdup(char *s);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strchr(char *s, int c);
int     ft_strlen(char *str);
// MAPA
t_map   *initi_map(char *file_path);
void    map_height(t_map *map, char *file_path);
int ft_read_map(t_map *map, char *file_path);
int    ft_map_wall(t_map *map);
int    validate_player_count(t_map  *map);
void    ft_free_map(t_map *map);
int ft_validate_char(char c);
int validate_map_elements(t_map *map);
int ft_map_width(t_map *map);

// FLOOD FILL
void    flood_fill(t_map *map, int x, int y);
int ft_validate_map_flood_fill(t_map *map);
void ft_fill_cpy(t_map *map);                       

//JANELA
t_window    *initi_win(t_map *map);
int close_window(t_window *window);
int keyboard(int keysym, t_game *game);

//IMAGEM
void render_map(t_game *game);
void put_image(t_game *game, void *img, int x, int y);
t_game   *init_img(t_window *window, t_map *map);

//MOVE PLAYER
//int keypress(int keycode, t_game *game);
void move_player(t_game *game, int x, int y);
void exit_game(t_game *game);
void free_images(t_game *game);
void free_game(t_game *game);
void free_window(t_window *window);
void ft_free_map_cpy(t_map *map);

void clear_get_next_line_buffer();
void destroy_window_and_mlx(t_window *window);
#endif
