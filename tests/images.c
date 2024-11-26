// gcc -o images tests/images.c -I ./mlx -I /opt/X11/include -L ./mlx -L /opt/X11/lib -lmlx -lXext -lX11 -lm && ./images

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*cursor;
	int		x;
	int		y;
	int		width;
	int		height;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307) // ESC no macOS
		exit(0);
	else if (keycode == 119) // W
		vars->y -= 10;
	else if (keycode == 97) // A
		vars->x -= 10;
	else if (keycode == 115) // S
		vars->y += 10;
	else if (keycode == 100) // D
		vars->x += 10;
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->cursor, vars->x, vars->y);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Cursor");
	vars.cursor = mlx_xpm_file_to_image(vars.mlx, "./cursor.xpm", &vars.width, &vars.height);
	if (!vars.cursor)
	{
		write(2, "Failed to load cursor image\n", 28);
		exit(1);
	}
	vars.x = 400; // Inicializa no centro da janela
	vars.y = 300;
	mlx_put_image_to_window(vars.mlx, vars.win, vars.cursor, vars.x, vars.y);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}

