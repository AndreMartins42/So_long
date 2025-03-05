#include "so_long.h"


void ft_free_map(t_map *map) {
    if (!map)
        return;
    if (map->map_data) {
        for (int i = 0; map->map_data[i]; i++) {
            free(map->map_data[i]);
        }
        free(map->map_data);
    }
    if (map->map_cpy) {
        for (int i = 0; map->map_cpy[i]; i++) {
            free(map->map_cpy[i]);
        }
        free(map->map_cpy);
    }
    free(map);
}


void ft_free_map_cpy(t_map *map)
{
    int i;

    if (!map || !map->map_cpy)
        return;
    for (i = 0; map->map_cpy[i]; i++)
        free(map->map_cpy[i]);
    free(map->map_cpy);
    map->map_cpy = NULL;
}


void free_images(t_game *game) {
    if (!game || !game->imgs || !game->window || !game->window->mlx)
        return;
    if (game->imgs->player_img)
        mlx_destroy_image(game->window->mlx, game->imgs->player_img);
    if (game->imgs->exit_img)
        mlx_destroy_image(game->window->mlx, game->imgs->exit_img);
    if (game->imgs->collect_img)
        mlx_destroy_image(game->window->mlx, game->imgs->collect_img);
    if (game->imgs->floor_img)
        mlx_destroy_image(game->window->mlx, game->imgs->floor_img);
    if (game->imgs->wall_img)
        mlx_destroy_image(game->window->mlx, game->imgs->wall_img);
    free(game->imgs);
}



void free_game(t_game *game)
{
/*     if (!game)
        return; */
    if (game->imgs)
        free_images(game);
    if (game->map)
        ft_free_map(game->map);
    if (game->window)
        free_window(game->window);
    free(game);
}


void free_window(t_window *window) {
    destroy_window_and_mlx(window);
}

void clear_get_next_line_buffer() {
    static char *buffer;
    
    if (buffer) {
        free(buffer);
        buffer = NULL;
    }
}