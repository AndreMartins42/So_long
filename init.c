/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:38:49 by anmendes          #+#    #+#             */
/*   Updated: 2025/02/15 17:48:05 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

t_game *init_game(void)
{
    t_game *game = malloc(sizeof(t_game));
    if (!game)
        return (printf("Erro ao alocar memória para o jogo\n"), NULL);
    game->window = malloc(sizeof(t_window));
    if (!game->window)
        return (printf("Erro ao alocar memória para a janela\n"), free(game), NULL);

    game->map = malloc(sizeof(t_map));
    if (!game->map)
        return (printf("Erro ao alocar memória map\n"), free(game->map), free(game), NULL);
    
    game->player = malloc(sizeof(t_player));
    game->player->y = 0;
    game->player->x = 0;
    if (!game->player)
        return (printf("Erro ao alocar memória player\n"), free(game->player), free(game), NULL);

    game->imgs = malloc(sizeof(t_imgs));
    if (!game->imgs)
        return (printf("Erro ao alocar memória imgs\n"), free(game->imgs), free(game), NULL);

    game->window->width = 500;
    game->window->height = 500;
    game->window->mlx = mlx_init();
    
    if (!game->window->mlx)
        return (printf("Erro ao inicializar mlx\n"), free(game->imgs), free(game->window), free(game), NULL);

    game->window->win = mlx_new_window(game->window->mlx, game->window->width, game->window->height, "My window");
    if (!game->window->win)
        return (printf("Erro ao criar a janela\n"), free(game->window->mlx), free(game->imgs),free(game->window), free(game), NULL);

    game->imgs->wall_img = mlx_xpm_file_to_image(game->window->mlx, "/home/anmendes/andre42/c.core/rank02/so_long (copy)/wall.xpm", &game->window->width, &game->window->height);
    if (!game->imgs->wall_img)
        return (printf("Erro ao carregar a imagem da parede\n"), NULL);

    game->imgs->floor_img = mlx_xpm_file_to_image(game->window->mlx, "/home/anmendes/andre42/c.core/rank02/so_long (copy)/chao.xpm", &game->window->width, &game->window->height);
    if (!game->imgs->floor_img)
        return (printf("Erro ao carregar a imagem chao\n"), NULL);

    game->imgs->player_img = mlx_xpm_file_to_image(game->window->mlx, "/home/anmendes/andre42/c.core/rank02/so_long (copy)/player.xpm", &game->window->width, &game->window->height);
    if (!game->imgs->player_img)
        return (printf("Erro ao carregar a imagem player\n"), NULL);

    game->imgs->exit_img = mlx_xpm_file_to_image(game->window->mlx, "/home/anmendes/andre42/c.core/rank02/so_long (copy)/exit.xpm", &game->window->width, &game->window->height);
    if (!game->imgs->exit_img)
        return (printf("Erro ao carregar a imagem exit\n"), NULL);

    game->imgs->collect_img = mlx_xpm_file_to_image(game->window->mlx, "/home/anmendes/andre42/c.core/rank02/so_long (copy)/Item.xpm", &game->window->width, &game->window->height);
    if (!game->imgs->collect_img)
        return (printf("Erro ao carregar a imagem collect\n"), NULL);
        
    return game;
}
