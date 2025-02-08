/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:57:35 by anmendes          #+#    #+#             */
/*   Updated: 2025/02/08 14:08:55 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	keyboard(int keysym, t_window *window)
{
	if (keysym == 65307)
		return (mlx_destroy_display(window->mlx), free(window->mlx), mlx_destroy_window(window->mlx, window->win), 1);
	return (0);
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

void draw_map(t_window *window, char **map)
{
    int i, j;
    int tile_size = 32; // Tamanho de cada tile (ajuste conforme necessário)

    // Carregar as imgns do mapa
    t_img_x wall, floor, player, collectible, exit;

    wall.image = mlx_xpm_file_to_image(window->mlx, "walls.xpm", &wall.width, &wall.height);
    floor.image = mlx_xpm_file_to_image(window->mlx, "floor.xpm", &floor.width, &floor.height);
    player.image = mlx_xpm_file_to_image(window->mlx, "player.xpm", &player.width, &player.height);
    collectible.image = mlx_xpm_file_to_image(window->mlx, "collectible.xpm", &collectible.width, &collectible.height);
    exit.image = mlx_xpm_file_to_image(window->mlx, "exit.xpm", &exit.width, &exit.height);

    // Verifica se as imgns foram carregadas corretamente
    if (!wall.image || !floor.image || !player.image || !collectible.image || !exit.image)
    {
        printf("Erro ao carregar as imgns\n");
        return;
    }

    // Percorrer o mapa
    for (i = 0; map[i]; i++)  // Itera pelas linhas do mapa
    {
        for (j = 0; map[i][j]; j++)  // Itera pelas colunas do mapa
        {
            // Determina qual imgm usar para o tile e desenha na janela
            if (map[i][j] == '1')  // Muro
                mlx_put_image_to_window(window->mlx, window->win, wall.image, j * tile_size, i * tile_size);
            else if (map[i][j] == '0')  // Chão
                mlx_put_image_to_window(window->mlx, window->win, floor.image, j * tile_size, i * tile_size);
            else if (map[i][j] == 'P')  // Jogador
                mlx_put_image_to_window(window->mlx, window->win, player.image, j * tile_size, i * tile_size);
            else if (map[i][j] == 'C')  // Coletáveis
                mlx_put_image_to_window(window->mlx, window->win, collectible.image, j * tile_size, i * tile_size);
            else if (map[i][j] == 'E')  // Saída
                mlx_put_image_to_window(window->mlx, window->win, exit.image, j * tile_size, i * tile_size);
        }
    }
}


int	main(void)
{
	t_window	window;
	t_img_x		img;
	//char		**map;

	window.width = 600;
	window.height = 800;
	//img.width = 32;
	//img.height = 32;
	
	window.mlx = mlx_init();
	if (!window.mlx)
		return (printf("Erro ao inicializar mlx"), 1);
	window.win = mlx_new_window(window.mlx, window.height, window.width, "My window");
	if (!window.win)
		return (mlx_destroy_display(window.mlx), free(window.mlx), printf("Erro ao criar a janela"), 0);
	
	char *map[] = {
        "111111111",
        "100011001",
        "1000CCC01",
        "1P100CCE1",
        "100000001",
        "111111111",
        NULL};

	draw_map(&window, map);
	
/* 	img.img = mlx_xpm_file_to_img(window.mlx, "/home/anmendes/andre42/c.core/rank02/so_long/bomb0.xpm", &img.width, &img.height);
	if (!img.img)	
		return (printf("Erro ao carregar a imgm\n"), 1);
	mlx_put_img_to_window(window.mlx, window.win, img.img, 32, 32);
 */	mlx_key_hook(window.win, keyboard, &window);
	mlx_hook(window.win, 17, 0, mouse, &window);
	mlx_loop(window.mlx);

	return (0);
}

// gcc window.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext