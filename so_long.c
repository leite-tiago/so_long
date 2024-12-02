/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:02:33 by tborges-          #+#    #+#             */
/*   Updated: 2024/12/02 19:42:45 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * 65307 - esc
 * 97 - a
 * 65361 - left arrow
 * 119 - w
 * 65362 - up arrow
 * 100 - d
 * 65363 - rigth arrow
 * 115 - s
 * 65364 - down arrow
 */
int	handle_keypress(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 65307)
		exit(0);
	else if (keycode == 97 || keycode == 65361)
		move_left(game);
	else if (keycode == 119 || keycode == 65362)
		move_up(game);
	else if (keycode == 100 || keycode == 65363)
		move_rigth(game);
	else if (keycode == 115 || keycode == 65364)
		move_down(game);
	if (game->map.count_c == 0)
		open_door(game);
	render_map(game);
	return (0);
}

/**
 * After the player collects all the collectibles the door must be opened.
 */
void	open_door(t_game *game)
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

/**
 * When the user clicks on the "X" of the window the program must end.
 */
int	close_window(void *param)
{
	(void)param;
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.mlx = mlx_init();
	game.count_moves = 0;
	init_map(argc, argv, &game.map);
	game.win = mlx_new_window(game.mlx, game.map.cols * SPRITE_SIZE,
			game.map.rows * SPRITE_SIZE, "so_long");
	load_textures(&game);
	render_map(&game);
	mlx_hook(game.win, ON_DESTROY, 0, close_window, &game);
	mlx_hook(game.win, ON_KEYDOWN, 1L << 0, handle_keypress, &game);
	mlx_expose_hook(game.win, render_map, &game);
	mlx_loop(game.mlx);
}
