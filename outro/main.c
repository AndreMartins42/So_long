#include "so_long.h"

int main(void)
{
    t_map *map;
    //t_window *window;
    //t_game  *game;
    char *file_path;

    file_path = "/home/andre/42/outro/map_0.ber";
    map = initi_map(file_path);
    if (!map)
        return (printf("mapa invalido\n"), 1);
    /* window = initi_win(map);
    game = init_img(window, map);
    if (!game || !game->map)
    {
        printf("Erro ao inicializar o jogo\n");
        return 1;
    }
    render_map(game);
	mlx_hook(game->window->win, 17, 0, close_window, window);
    mlx_hook(window->win, 2, 1L<<0, keyboard, game);
    mlx_loop(game->window->mlx);
    free_game(game);
    free(map);
    free(window);
     */
    
    return (0);
}


/*     int i = 0;
    while(map->map_cpy[i])
    {
        printf ("%s\n", map->map_cpy[i]);
        i++;
    }
    while(map->map_data[i])
    {
        printf ("%s\n", map->map_data[i]);
        i++;
    }
    ft_free_map(map); */