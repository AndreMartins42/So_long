/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:23:03 by anmendes          #+#    #+#             */
/*   Updated: 2025/02/01 14:25:17 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include <stdlib.h>

#define WIDTH 600
#define HEIGHT 800

int close_window(int keycode, void *mlx)
{
    if (keycode == 65307)
        mlx_destroy_window(mlx, mlx);
    return (0);
}
int main(void)
{
    void *mlx_connect;
    void *mlx_window;

    mlx_connect = mlx_init();
    if (mlx_connect == NULL)
        return (1);
    mlx_window = mlx_new_window(mlx_connect, HEIGHT, WIDTH, "My window");
    if (mlx_window == NULL)
    {
        free(mlx_window);
        return (1);
    }
    //mlx_loop(mlx_connect);
    mlx_key_hook(mlx_window, close_window, mlx_connect);
    mlx_destroy_window(mlx_connect, mlx_window);
    mlx_destroy_display(mlx_connect);
    free(mlx_connect);
} 
//gcc window.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext