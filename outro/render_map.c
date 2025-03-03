#include "so_long.h"

void render_map(t_game *game)
{
	int x, y;

	y = 0;
	while (game->map->map_data[y])
	{
		x = 0;
		while (game->map->map_data[y][x])
		{
			//mlx_put_image_to_window(game->window->mlx, game->window->win, game->imgs->floor_img, (x * 24), (y * 24));
			if (game->map->map_data[y][x] == '1')
				put_image(game, game->imgs->wall_img, x, y);
			if (game->map->map_data[y][x] == '0')
				put_image(game, game->imgs->floor_img, x, y);
			if (game->map->map_data[y][x] == 'C')
				put_image(game, game->imgs->collect_img, x, y);
			if (game->map->map_data[y][x] == 'P')
				put_image(game, game->imgs->player_img, x, y);
			if (game->map->map_data[y][x] == 'E')
				put_image(game, game->imgs->exit_img, x, y);
			x++;
		}
		y++;
	}
	
}
void put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->window->mlx, game->window->win, img, x * 24, y * 24);
}
