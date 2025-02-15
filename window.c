/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2424/02/08 10:57:35 by anmendes          #+#    #+#             */
/*   Updated: 2025/02/15 16:51:54 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	keyboard(int keysym, t_game *game)
{
	if (keysym == 65307)
		mouse(game);
   return (1);
}

int	mouse(t_game *game)
{
	if (game->window->win)
	{
		mlx_destroy_window(game->window->mlx, game->window->win);
		game->window->win = NULL;
	}
	if (game->window->mlx)
	{
		mlx_destroy_display(game->window->mlx);
		free(game->window->mlx);
		game->window->mlx = NULL;
	}
	return (0);
}
void put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->window->mlx, game->window->win, img, x * 24, y * 24);
}

void render_map(t_game *game)
{
	int x, y;

	y = 0;
	
	while (game->map->map_data[y])
	{
		x = 0;
		while (game->map->map_data[y][x])
		{
			mlx_put_image_to_window(game->window->mlx, game->window->win, game->imgs->floor_img, (x * 24), (y * 24));
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

int	main(void)
{
	t_game	*game;
	t_map	*map;
	
	game = init_game();
	if (!game)
		return (0);
	//map = malloc(sizeof(t_map));
	if (ft_check_map("/home/anmendes/andre42/c.core/rank02/so_long (copy)/teste.ber"))
	//map->map_data = ft_check_map("/home/anmendes/andre42/c.core/rank02/so_long (copy)/teste.ber");
	
	render_map(game);
	mlx_key_hook(game->window->win, keyboard, game->window);
	mlx_hook(game->window->win, 24, 0, mouse, game->window);
	mlx_loop(game->window->mlx);

	free(game->imgs);
    free(game->window);
    free(game);

	return (0);
}
// gcc window.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext



/* 	fd = open("map_0.ber", O_RDONLY);
    result = ft_check_map(fd);
	if (result == 1)
		return (printf("MAPA INVALIDO\n"), 1);
	
	while ((rst = get_next_line(fd)) != NULL)
	{
		map[i] = rst;
		free(rst);
		i++;
	}
	close(fd); */
/*  	char *map[] = {
		"111111", 
		"100C0E",
		"10CPC1",
		"111111",
		NULL
	};  */


	/* void move_player(int dx, int dy, t_game *game)
{
    int new_x = game->player.x + dx;
    int new_y = game->player.y + dy;

    if (game->map.data[new_y][new_x] != '1') // Evita sair do mapa
    {
        game->map->map_data[game->player.y][game->player.x] = '0'; // Remove o jogador da posição antiga
        game->player.x = new_x;
        game->player.y = new_y;
        game->map.data[new_y][new_x] = 'P'; // Move o jogador
        render_map(&game->window, game->map.data);
    }
} */