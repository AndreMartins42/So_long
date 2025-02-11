/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2424/02/08 10:57:35 by anmendes          #+#    #+#             */
/*   Updated: 2025/02/11 19:55:35 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void move_player_up(int x, int y, t_player *player)
{
	if (map[player->y + y][player->x + x] != '1')
	{
		map[player->y][player->x] = '0';
		player->x += x;
		player->y += y;
		map[player->y][player->x] = 'P';
		render_map();		
	}
}

int	keyboard(int keysym, t_window *window)
{
	if (keysym == 65307)
    {
		mlx_destroy_window(window->mlx, window->win);
        mlx_destroy_display(window->mlx);
        free(window->mlx);
		return (0);
    }
	else if (keysym == 119)
		move_player_up();
    return (1);
}

int	mouse(t_window *window)
{
	if (window->win)
	{
		mlx_destroy_window(window->mlx, window->win);
		window->win = NULL;
	}
	if (window->mlx)
	{
		mlx_destroy_display(window->mlx);
		free(window->mlx);
		window->mlx = NULL;
	}
	return (0);
}

void render_map(t_window *game, char **map)
{
	int x, y;

	y = 0;
	
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->floor_img, (x * 24), (y * 24));
			if (map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img, (x * 24), (y * 24));
			if (map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor_img, (x * 24), (y * 24));
			if (map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collect_img, (x * 24), (y * 24));
			if (map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player_img, (x * 24), (y * 24));
			if (map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img, (x * 24), (x * 24));
			x++;
		}
		y++;
	}
	
}

int	main(void)
{
	t_window	window;
	int fd;
	int result;
	char *rst;
	//char **map;
	int i = 0;

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
 	char *map[] = {
		"111111", 
		"100C0E",
		"10CPC1",
		"111111",
		NULL
	}; 
 
	window.width = 500;
	window.height = 500;
	
	window.mlx = mlx_init();
	if (!window.mlx)
		return (printf("Erro ao inicializar mlx"), 1);
	
	window.win = mlx_new_window(window.mlx, window.height, window.width, "My window");
	if (!window.win)
		return (mlx_destroy_display(window.mlx), free(window.mlx), printf("Erro ao criar a janela"), 0);
	
	window.wall_img = mlx_xpm_file_to_image(window.mlx, "/home/anmendes/andre42/c.core/rank02/so_long/wall.xpm", &window.width, &window.height);
	if (!window.wall_img)	
		return (printf("Erro ao carregar a imgm\n"), 1);

	window.floor_img = mlx_xpm_file_to_image(window.mlx, "/home/anmendes/andre42/c.core/rank02/so_long/chao.xpm", &window.width, &window.height);
	if (!window.floor_img)	
		return (printf("Erro ao carregar a imgm\n"), 1);

	window.collect_img = mlx_xpm_file_to_image(window.mlx, "/home/anmendes/andre42/c.core/rank02/so_long/Item.xpm", &window.width, &window.height);
	if (!window.collect_img)	
		return (printf("Erro ao carregar a imgm\n"), 1);

	window.player_img = mlx_xpm_file_to_image(window.mlx, "/home/anmendes/andre42/c.core/rank02/so_long/player.xpm", &window.width, &window.height);
	if (!window.player_img)	
		return (printf("Erro ao carregar a imgm\n"), 1);

	window.exit_img = mlx_xpm_file_to_image(window.mlx, "/home/anmendes/andre42/c.core/rank02/so_long/exit.xpm", &window.width, &window.height);
	if (!window.exit_img)	
		return (printf("Erro ao carregar a imgm\n"), 1);

	render_map(&window, map);  
	mlx_key_hook(window.win, keyboard, &window);
	mlx_hook(window.win, 24, 0, mouse, &window);
	mlx_loop(window.mlx);

	return (0);
}
// gcc window.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext