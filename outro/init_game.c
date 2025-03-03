#include "so_long.h"

t_map *initi_map(char *file_path)
{
    t_map *map;

    map = malloc(sizeof(t_map));
    if (!map)
        return (free(map), NULL);
    map_height(map, file_path); //largura e altura
    ft_read_map(map, file_path); //tem que ser dps pq usa altura e largura // fazer protecoes de TUDO
    if (!map->map_data)
        return (free(map->map_data), ft_free_map(map), NULL);
    if (ft_map_wall(map) == 1)
        return (ft_free_map(map), NULL);
    if (validate_player_count(map) == 1)
        return (ft_free_map(map), NULL);
    if (validate_map_elements(map) == 1)
        return (ft_free_map(map), NULL);
    if (ft_map_width(map) == 1)
        return (ft_free_map(map), NULL);
    ft_fill_cpy(map);
    flood_fill(map, map->player_x, map->player_y);
    if (ft_validate_map_flood_fill(map) == 1)
    return (printf("Mapa invalido apos flood fill\n"), ft_free_map(map), NULL);
    return (map);
}
t_window    *initi_win(t_map *map)
{
    t_window *window;

    window = malloc(sizeof(t_window));
    if (!window)
        return (free(window), NULL);
    window->width = map->width * 24;
    window->height = map->height * 24;
    window->mlx = mlx_init();
    if (!window->mlx)
        return (free(window->mlx), free(window), NULL);
    window->win = mlx_new_window(window->mlx, window->width, window->height, "SO_LONG");
    if (!window->win)
        return (free(window->win), free(window), NULL);
    return (window);
}

t_game   *init_img(t_window *window, t_map *map)
{
    t_game *game = malloc(sizeof(t_game));
     if (!game)
        return (printf("Erro ao alocar memória para o jogo\n"), NULL);
 
    game->window = window;
    game->map = map;
    game->imgs = malloc(sizeof(t_img));
    if (!game->imgs)
        return (free(game), printf("Erro ao alocar memória para a janela\n"), NULL);
    game->imgs->wall_img = mlx_xpm_file_to_image(game->window->mlx, "/home/andre/42/outro/wall.xpm", &game->window->width, &game->window->height);
    if (!game->imgs->wall_img)
        return (free_images(game), free(game->imgs), free(game), printf("Erro ao carregar a imagem da parede\n"), NULL);
    game->imgs->floor_img = mlx_xpm_file_to_image(game->window->mlx, "/home/andre/42/outro/chao.xpm", &game->window->width, &game->window->height);
    if (!game->imgs->floor_img)
        return (free_images(game), free(game->imgs), free(game), printf("Erro ao carregar a imagem chao\n"), NULL);
    game->imgs->player_img = mlx_xpm_file_to_image(game->window->mlx, "/home/andre/42/outro/player.xpm", &game->window->width, &game->window->height);
    if (!game->imgs->player_img)
        return (free_images(game), free(game->imgs), free(game), printf("Erro ao carregar a imagem player\n"), NULL);
    game->imgs->exit_img = mlx_xpm_file_to_image(game->window->mlx, "/home/andre/42/outro/exit.xpm", &game->window->width, &game->window->height);
    if (!game->imgs->exit_img)
        return (free_images(game), free(game->imgs), free(game), printf("Erro ao carregar a imagem exit\n"), NULL);
    game->imgs->collect_img = mlx_xpm_file_to_image(game->window->mlx, "/home/andre/42/outro/Item.xpm", &game->window->width, &game->window->height);
    if (!game->imgs->collect_img)
        return (free_images(game), free(game->imgs), free(game), printf("Erro ao carregar a imagem collect\n"), NULL);
    return (game);
}

