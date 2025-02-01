/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:23:03 by anmendes          #+#    #+#             */
/*   Updated: 2025/02/01 12:54:30 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include <stdlib.h>

/* #define WIDTH 800
#define HEIGHT 600

int close_window(int keycode, void *mlx)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(mlx, mlx);
        exit(0);
    }
    return(0);
}
int main(void)
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "meu jogo");
    mlx_key_hook(win, close_window, mlx);
    mlx_loop(mlx);
} */
// mlx_loop - funcao pra deixar janela aberta
int main(void)
{
    void *mlx_ptr;

    mlx_ptr = mlx_init();
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
} 