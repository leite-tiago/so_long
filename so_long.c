/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:02:33 by tborges-          #+#    #+#             */
/*   Updated: 2024/12/02 11:23:42 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Run:
 * gcc -o so_long so_long.c -I ./mlx -I /opt/X11/include -L ./mlx -L /opt/X11/lib -lmlx -lXext -lX11 -lm && ./so_long
 */

#include "so_long.h"

int	handle_keypress(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 65307) // esc
		exit(0);
	else if (keycode == 97 || keycode == 65361) // a or left arrow
	{
		// write(1, "left\n", 5);
		move_left(game);
	}
	else if (keycode == 119 || keycode == 65362) // w or up arrow
	{
		// write(1, "up\n", 3);
		move_up(game);
	}
	else if (keycode == 100 || keycode == 65363) // d or rigth arrow
	{
		// write(1, "rigth\n", 6);
		move_rigth(game);
	}
	else if (keycode == 115 || keycode == 65364) // s or down arrow
	{
		// write(1, "down\n", 5);
		move_down(game);
	}
	if (game->map.count_c == 0)
	{
		t_textures	*textures;
		int			height;
		int			width;

		textures = &game->textures;
		height = SPRITE_SIZE;
		width = SPRITE_SIZE;
		textures->exit = mlx_xpm_file_to_image(game->mlx, "assets/open_door.xpm",
			&height, &width);
	}
	render_map(game);
	ft_printf("Moves: %d\n", game->count_moves);
	return 0;
}

/**
 * When the user clicks on the "X" of the window the program must end.
 */
int	close_window(void *param)
{
	(void)param;
	exit(0);
}

int main(int argc, char **argv)
{
	t_game	game;

	game.mlx = mlx_init();
	game.count_moves = 0;
	init_map(argc, argv, &game.map);
	game.win = mlx_new_window(game.mlx, game.map.cols * SPRITE_SIZE, game.map.rows
			* SPRITE_SIZE, "So Long");
	load_textures(&game);
	render_map(&game);
	mlx_hook(game.win, ON_DESTROY, 0, close_window, &game);
	mlx_hook(game.win, ON_KEYDOWN, 1L << 0, handle_keypress, &game);
	mlx_loop(game.mlx);
}
