// gcc -o movable_circle tests/movable_circle.c -I ./mlx -I /opt/X11/include -L ./mlx -L /opt/X11/lib -lmlx -lXext -lX11 -lm && ./movable_circle

#include <mlx.h>
#include <stdlib.h>
#include <math.h> // Para cálculos com o círculo

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		x;  // Coordenada X do círculo
	int		y;  // Coordenada Y do círculo
}				t_vars;

// Função para desenhar um círculo
void	draw_circle(t_vars *vars, int x0, int y0, int radius, int color)
{
	int	x = radius;
	int	y = 0;
	int	err = 0;

	while (x >= y)
	{
		mlx_pixel_put(vars->mlx, vars->win, x0 + x, y0 + y, color);
		mlx_pixel_put(vars->mlx, vars->win, x0 + y, y0 + x, color);
		mlx_pixel_put(vars->mlx, vars->win, x0 - y, y0 + x, color);
		mlx_pixel_put(vars->mlx, vars->win, x0 - x, y0 + y, color);
		mlx_pixel_put(vars->mlx, vars->win, x0 - x, y0 - y, color);
		mlx_pixel_put(vars->mlx, vars->win, x0 - y, y0 - x, color);
		mlx_pixel_put(vars->mlx, vars->win, x0 + y, y0 - x, color);
		mlx_pixel_put(vars->mlx, vars->win, x0 + x, y0 - y, color);
		if (err <= 0)
		{
			y += 1;
			err += 2 * y + 1;
		}
		if (err > 0)
		{
			x -= 1;
			err -= 2 * x + 1;
		}
	}
}

// Lida com eventos de teclado
int	handle_keypress(int keycode, t_vars *vars)
{
	// Fecha o programa ao pressionar ESC
	if (keycode == 65307) // ESC no macOS
		exit(0);

	// Atualiza posição do círculo
	if (keycode == 119) // W
		vars->y -= 10;
	else if (keycode == 97) // A
		vars->x -= 10;
	else if (keycode == 115) // S
		vars->y += 10;
	else if (keycode == 100) // D
		vars->x += 10;

	// Limpa a janela e redesenha o círculo
	mlx_clear_window(vars->mlx, vars->win);
	draw_circle(vars, vars->x, vars->y, 50, 0xFFFFFF); // Branco
	return (0);
}

// Função principal
int	main(void)
{
	t_vars	vars;

	// Inicializa MiniLibX e cria janela
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Move the Circle");

	// Posição inicial do círculo
	vars.x = 400;
	vars.y = 300;

	// Desenha o círculo inicial
	draw_circle(&vars, vars.x, vars.y, 50, 0xFFFFFF);

	// Registra evento de tecla pressionada
	mlx_hook(vars.win, 2, 1L << 0, handle_keypress, &vars);

	// Inicia o loop principal
	mlx_loop(vars.mlx);
}
