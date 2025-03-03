#include "so_long.h"

void ft_free_map(t_map *map)
{
    int i;

    if (!map)
        return;
    if (map->map_data)
    {
        i = 0;
        while (map->map_data[i])
        {
            free(map->map_data[i]);
            i++;
        }
        free(map->map_data);
    }
    if (map->map_cpy)
    {
        i = 0;
        while (map->map_cpy[i])
        {
            free(map->map_cpy[i]);
            i++;
        }
        free(map->map_cpy);
    }
    free(map);
}
void free_images(t_game *game)
{
    if (game->imgs)
    {
        if (game->imgs->wall_img)
            mlx_destroy_image(game->window->mlx, game->imgs->wall_img);
        if (game->imgs->floor_img)
            mlx_destroy_image(game->window->mlx, game->imgs->floor_img);
        if (game->imgs->player_img)
            mlx_destroy_image(game->window->mlx, game->imgs->player_img);
        if (game->imgs->exit_img)
            mlx_destroy_image(game->window->mlx, game->imgs->exit_img);
        if (game->imgs->collect_img)
            mlx_destroy_image(game->window->mlx, game->imgs->collect_img);
        }
    free(game->imgs); // Libera a estrutura de imagens
    game->imgs = NULL; // Evita uso de memória já liberada
}

void free_game(t_game *game)
{
    if (game)
    {
        if (game->imgs)
            free_images(game);  // Liberar todas as imagens
        if (game->window)
        {
            if (game->window->win)
                mlx_destroy_window(game->window->mlx, game->window->win);
            free(game->window);
        }
        if (game->map)
            ft_free_map(game->map);  // Liberar o mapa
        free(game);
    }
}

