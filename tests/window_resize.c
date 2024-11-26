
// gcc -o window_resize tests/window_resize.c -I ./mlx -I /opt/X11/include -L ./mlx -L /opt/X11/lib -lmlx -lXext -lX11 -lm && ./window_resize

#include <mlx.h>
#include <stdio.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

// Função chamada quando a janela é redimensionada
int	window_resize(void *param)
{
	(void)param; // Parametro não usado, mas necessário para compatibilidade
	printf("Window resized!\n");
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Resize Event");

	// Hook para o evento de redimensionamento (evento 25)
	mlx_hook(vars.win, 25, 1L << 18, window_resize, &vars);

	mlx_loop(vars.mlx);
}
