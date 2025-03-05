#include "so_long.h"

int main(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    t_map *map;
    t_window *window;
    t_game  *game;

    map = initi_map(argv[1]);
    if (!map)
        return (printf("mapa invalido\n"), 1);
  
    window = initi_win(map);
    if (!window)
    {
        ft_free_map(map);
        free_window(window);
    }

    game = init_img(window, map);
        if(!game)
            free_game(game);
    render_map(game);
    mlx_hook(game->window->win, 17, 0, close_window, window);
    mlx_hook(window->win, 2, 1L<<0, keyboard, game);
    mlx_loop(game->window->mlx);
    //free_game(game); 
    //clear_get_next_line_buffer();
    ft_free_map(map);
    return (0);
}
