// gcc -o hooks tests/hooks.c -I ./mlx -I /opt/X11/include -L ./mlx -L /opt/X11/lib -lmlx -lXext -lX11 -lm && ./hooks

// #include <mlx.h>
// #include <stdio.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	key_hook(int keycode, t_vars *vars)
// {
// 	printf("Hello from key_hook!\n");
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	mlx_loop(vars.mlx);
// }


// código para descobrir keycodes
#include <mlx.h>
#include <stdio.h> // Para printf

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_press(int keycode, t_vars *vars)
{
	printf("Key pressed: %d\n", keycode); // Exibe o keycode da tecla pressionada
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Keycode Finder");
	mlx_hook(vars.win, 2, 1L<<0, key_press, &vars); // Evento de tecla pressionada
	mlx_loop(vars.mlx);
}
