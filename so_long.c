/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:02:33 by tborges-          #+#    #+#             */
/*   Updated: 2024/11/19 11:33:56 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Run:
 * gcc -o so_long so_long.c -I ./mlx -I /opt/X11/include -L ./mlx -L /opt/X11/lib -lmlx -lXext -lX11 -lm && ./so_long
 */

#include "so_long.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	handle_keypress(int keycode, t_vars *vars)
{
	if (keycode == 65307) // esc
		exit(0);
	else if (keycode == 97 || keycode == 65361) // a or left arrow
		// move_left();
	{
		write(1, "left\n", 5);
	}
	else if (keycode == 119 || keycode == 65362) // w or up arrow
		// move_up();
	{
		write(1, "up\n", 3);
	}
	else if (keycode == 100 || keycode == 65363) // d or rigth arrow
		// move_rigth();
	{
		write(1, "rigth\n", 6);
	}
	else if (keycode == 115 || keycode == 65364) // s or down arrow
		// move_down();
	{
		write(1, "down\n", 5);
	}

	return (0);
}

/**
 * When the user clicks on the "x" of the window the program must end.
 */
int	close_window(void *param)
{
	(void)param;
	exit(0);
}

int main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "so_long");

	mlx_hook(vars.win, ON_DESTROY, 0, close_window, &vars);
	mlx_hook(vars.win, ON_KEYDOWN, 1L<<0, handle_keypress, &vars);

	mlx_loop(vars.mlx);
}
