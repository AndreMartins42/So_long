#include "so_long.h"


t_map *initi_map(char *file_path)
{
    t_map *map;

    map = malloc(sizeof(t_map));
    if (!map)
        return (NULL);

    map_height(map, file_path);
    ft_read_map(map, file_path);
    if (!map->map_data)
        return (ft_free_map(map), NULL);
    if (ft_map_wall(map) == 1 || validate_player_count(map) == 1 || validate_map_elements(map) == 1 || ft_map_width(map) == 1)
        return (ft_free_map(map), NULL);
    ft_fill_cpy(map);
    flood_fill(map, map->player_x, map->player_y);
    if (ft_validate_map_flood_fill(map) == 1)
        return (ft_free_map_cpy(map), ft_free_map(map), printf("Mapa inválido após flood fill\n"), NULL);
    ft_free_map_cpy(map);
    return (map);
}

t_window    *initi_win(t_map *map)
{
    t_window *window;

    window = malloc(sizeof(t_window));
    if (!window)
        return (NULL);
    window->width = map->width * 24;
    window->height = map->height * 24;
    window->mlx = mlx_init();
    if (!window->mlx)
        return (free_window(window), NULL);
    window->win = mlx_new_window(window->mlx, window->width, window->height, "so_long");
    if (!window->win)
        return (free(window->mlx), free(window), NULL);
    return (window);
}

t_game *init_img(t_window *window, t_map *map)
{
    t_game *game; 
    
    game = malloc(sizeof(t_game));
    if (!game)
        return (printf("Erro ao alocar memória para o jogo\n"), NULL);
    game->count = 0;
    game->window = window;
    game->map = map;
    game->imgs = malloc(sizeof(t_imgs));
    if (!game->imgs)
        return (printf("Erro ao alocar memória para a janela\n"), free(game), NULL);
    game->imgs->wall_img = mlx_xpm_file_to_image(game->window->mlx, "/home/andre/42/so_long/textures/wall.xpm", &game->window->width, &game->window->height);
    if (!game->imgs->wall_img)
        return (printf("Erro ao carregar a imagem da parede\n"), free(game->imgs), free(game), NULL);
    game->imgs->floor_img = mlx_xpm_file_to_image(game->window->mlx, "/home/andre/42/so_long/textures/chao.xpm", &game->window->width, &game->window->height);
    if (!game->imgs->floor_img)
        return (printf("Erro ao carregar a imagem chao\n"), free(game->imgs), free(game), NULL);
    //mlx_destroy_image(game->window->mlx, game->imgs->wall_img);
    game->imgs->player_img = mlx_xpm_file_to_image(game->window->mlx, "/home/andre/42/so_long/textures/player.xpm", &game->window->width, &game->window->height);
    if (!game->imgs->player_img)
    {
        mlx_destroy_image(game->window->mlx, game->imgs->wall_img);
        mlx_destroy_image(game->window->mlx, game->imgs->floor_img);
        free(game->imgs);
        free(game);
        return (printf("Erro ao carregar a imagem player\n"), NULL);
    }
    game->imgs->exit_img = mlx_xpm_file_to_image(game->window->mlx, "/home/andre/42/so_long/textures/exit.xpm", &game->window->width, &game->window->height);
    if (!game->imgs->exit_img)
    {
        mlx_destroy_image(game->window->mlx, game->imgs->wall_img);
        mlx_destroy_image(game->window->mlx, game->imgs->floor_img);
        mlx_destroy_image(game->window->mlx, game->imgs->player_img);
        free(game->imgs);
        free(game);
        return (printf("Erro ao carregar a imagem exit\n"), NULL);
    }
    game->imgs->collect_img = mlx_xpm_file_to_image(game->window->mlx, "/home/andre/42/so_long/textures/Item.xpm", &game->window->width, &game->window->height);
    if (!game->imgs->collect_img)
    {
        mlx_destroy_image(game->window->mlx, game->imgs->wall_img);
        mlx_destroy_image(game->window->mlx, game->imgs->floor_img);
        mlx_destroy_image(game->window->mlx, game->imgs->player_img);
        mlx_destroy_image(game->window->mlx, game->imgs->exit_img);
        free(game->imgs);
        free(game);
        return (printf("Erro ao carregar a imagem collect\n"), NULL);
    }
    return (game);
}

