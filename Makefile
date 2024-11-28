# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 10:04:55 by tborges-          #+#    #+#              #
#    Updated: 2024/11/28 12:23:08 by tborges-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome do executável
NAME = so_long

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./mlx -I ./libft -I /opt/X11/include

# Diretórios e arquivos
SRCS = so_long.c frees.c error.c map_init.c map_read.c map_validation.c
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
