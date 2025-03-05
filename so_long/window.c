#include "so_long.h"

int keyboard(int keysym, t_game *game)
{  
    if (keysym == 65307)
    {
        close_window(game->window);
        exit(0);
    }
    else if (keysym == 119)
       move_player(game, 0, -1);
    else if (keysym == 97)
        move_player(game, -1, 0);
    else if (keysym == 115)
        move_player(game, 0, 1);
    else if (keysym == 100)
        move_player(game, 1, 0);
    game->count++;
    printf("Movs: %d\n", game->count);
    return (0);
}

void destroy_window_and_mlx(t_window *window) {
    if (window && window->mlx) {
        if (window->win) {
            mlx_clear_window(window->mlx, window->win);
            mlx_destroy_window(window->mlx, window->win);
        }
        mlx_loop_end(window->mlx);
        mlx_destroy_display(window->mlx);
        free(window->mlx);
        window->mlx = NULL;
    }
    if (window) {
        free(window);
    }
}

int close_window(t_window *window)
{
    destroy_window_and_mlx(window);
    exit(0);
    return (0);
}


void move_player(t_game *game, int x, int y)
{
    int new_x;
    int new_y;

    new_x = game->map->player_x + x;
    new_y = game->map->player_y + y;

    if (game->map->map_data[new_y][new_x] == '1')
        return ;

    if (game->map->map_data[new_y][new_x] == 'C')
        game->map->c--;
    
    if (game->map->map_data[new_y][new_x] == 'E' && game->map->c == 0) 
        exit_game(game);
    if (game->map->map_data[new_y][new_x] == 'E' && game->map->c > 0)
        return ;
    game->map->map_data[game->map->player_y][game->map->player_x] = '0';
    game->map->map_data[new_y][new_x] = 'P';
    game->map->player_x = new_x;
    game->map->player_y = new_y;

    render_map(game);
}

void exit_game(t_game *game)
{
    if (game && game->window) {
        destroy_window_and_mlx(game->window);
    }
    if (game) {
        free(game);
    }
    exit(0);
}
