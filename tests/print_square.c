#include <mlx.h>

/**
 * gcc -o print_square tests/print_square.c -I ./mlx -I /opt/X11/include -L ./mlx -L /opt/X11/lib -lmlx -lXext -lX11 -lm && ./print_square
 */

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	/**
	 * The line_length differs from the actual window width.
	 * We therefore should ALWAYS calculate the memory offset
	 * using the line length set by mlx_get_data_addr.
	 *
	 * int offset = (y * line_length + x * (bits_per_pixel / 8));
	 */
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Green Square!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	for (int y = 290; y <= 790; y++)
	{
		if (y == 290 || y == 790) // first or last line
		{
			for (int x = 710; x <= 1210; x++)
				my_mlx_pixel_put(&img, x, y, 0x0000FF00);
		}
		else
		{
			my_mlx_pixel_put(&img, 710, y, 0x0000FF00);
			my_mlx_pixel_put(&img, 1210, y, 0x0000FF00);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
