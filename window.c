/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:23:03 by anmendes          #+#    #+#             */
/*   Updated: 2025/02/03 20:12:20 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WIDTH 600
#define HEIGHT 800

int	keyboard(int keysym, t_vars *data)
{
	if (keysym == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit (1);
	}
	return (0);
}

int	mouse(t_vars *data)
{
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
	exit (0);
	return (0);
}

int	main(void)
{
	t_vars	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, HEIGHT, WIDTH, "My window");
	mlx_key_hook(data.win, keyboard, &data);
	mlx_hook(data.win, 17, 0, mouse, &data);
	mlx_loop(data.mlx);
}
//gcc window.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext