// gcc -o rainbow_animation tests/rainbow_animation.c -I ./mlx -I /opt/X11/include -L ./mlx -L /opt/X11/lib -lmlx -lXext -lX11 -lm && ./rainbow_animation

/**
 * Render a moving rainbow that shifts through all colors
 * (screen turns red, becomes green and then becomes blue,
 * then starts all over again).
 */

#include <mlx.h>
#include <stdlib.h>
#include <math.h> // Para o fmod

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color_step;
	float	color_phase;
}				t_vars;

// Cria uma cor em formato TRGB com base em valores de red, green e blue
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// Calcula a cor com base em um ciclo contínuo de red-green-blue
int	calculate_color(float phase)
{
	int r = (int)(128 + 127 * sin(phase));
	int g = (int)(128 + 127 * sin(phase + 2.0 * M_PI / 3.0));
	int b = (int)(128 + 127 * sin(phase + 4.0 * M_PI / 3.0));
	return create_trgb(0, r, g, b);
}

// Define a cor de um pixel no buffer da imagem
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// Função que é chamada para renderizar cada frame
int	render_next_frame(t_vars *vars)
{
	int	x, y;

	// Atualiza a fase da cor para o próximo frame
	vars->color_phase += 0.02;

	// Preenche a imagem com a nova cor calculada
	for (y = 0; y < 600; y++)
	{
		for (x = 0; x < 800; x++)
		{
			int color = calculate_color(vars->color_phase);
			my_mlx_pixel_put(vars, x, y, color);
		}
	}

	// Exibe a imagem atualizada na janela
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	// Inicializa MiniLibX e cria janela
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Rainbow Animation");

	// Cria uma imagem para manipular pixels
	vars.img = mlx_new_image(vars.mlx, 800, 600);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);

	// Inicializa variáveis de animação
	vars.color_phase = 0.0;

	// Registra o loop de renderização
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);

	// Inicia o loop principal
	mlx_loop(vars.mlx);
}
