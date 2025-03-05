# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 12:07:11 by anmendes          #+#    #+#              #
#    Updated: 2024/11/12 15:32:32 by anmendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g
NAME	=	so_long

MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lX11 -lXext -lm

SOURCES = main.c init_game.c get_next_line.c get_next_line_utils.c flood_fill.c\
map_elements.c map_free.c map_height.c map_read.c map_wall.c render_map.c window.c

OBJ = $(SOURCES:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS) -I$(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
