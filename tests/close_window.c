// gcc -o close_window tests/close_window.c -I ./mlx -I /opt/X11/include -L ./mlx -L /opt/X11/lib -lmlx -lXext -lX11 -lm && ./close_window

#include <mlx.h>
#include <stdlib.h> // Para exit()

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

// Função chamada ao clicar na cruz vermelha
int	close_window(void *param)
{
	(void)param; // Não usamos o parâmetro aqui
	exit(0); // Encerra o programa
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Close Event");

	// Hook para o evento de fechamento da janela (evento 17)
	mlx_hook(vars.win, 17, 0, close_window, &vars);

	mlx_loop(vars.mlx);
}
