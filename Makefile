# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tborges- <tborges-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 10:04:55 by tborges-          #+#    #+#              #
#    Updated: 2025/05/25 22:48:21 by tborges-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome do executável
NAME = so_long

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./mlx -I ./libft -I /opt/X11/include

# Diretórios e arquivos
SRCS = so_long.c frees.c error.c map/map_init.c map/map_read.c map/map_validation.c map/map_validation_aux.c render.c input.c input_aux.c
OBJS = $(SRCS:.c=.o)

# Diretório da libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Bibliotecas externas
MLX_FLAGS = -L ./mlx -L /opt/X11/lib -lmlx -lXext -lX11 -lm

# Regras
all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all


# NAME = so_long

# SRC_DIR = src
# SRCS = so_long.c frees.c error.c map/map_init.c map/map_read.c \
# 		map/map_validation.c map/map_validation_aux.c render.c \
# 		input.c input_aux.c
# OBJS = $(SRCS:.c=.o)

# INCLUDES = -I/usr/include -Imlx -I$(LIBFT_DIR) -I$(MLX_DIR)

# LIBFT_DIR = ./libft
# LIBFT = ./libft/libft.a

# MLX_DIR = ./minilibx-linux
# MLX_LIB = $(MLX_DIR)/libmlx.a
# MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11

# CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# RM = rm -rf

# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(MAKE) -C $(LIBFT_DIR)
# 	$(MAKE) -C $(MLX_DIR)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

# clean:
# 	$(MAKE) clean -C $(LIBFT_DIR)
# 	$(MAKE) clean -C $(MLX_DIR)
# 	$(RM) $(OBJS)

# fclean: clean
# 	$(MAKE) fclean -C $(LIBFT_DIR)
# 	$(RM) $(NAME)

# re: fclean all

# .PHONY: all clean fclean re
