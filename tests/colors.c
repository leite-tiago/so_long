#include <mlx.h>
#include <unistd.h>

/**
 * create an TRGB int (0xTTRRGGBB)
 * T - Transparency
 * R - Red component
 * G - Green component
 * B - Blue component
 */
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// get each component //
int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
////////////////////////

/**

	* is a function that accepts a double (distance) and a int (color) as arguments,
 * 0 will add no shading to the color,
	whilst 1 will make the color completely dark.
 * 0.5 will dim it halfway, and .25 a quarter way. You get the point.
 */
int	add_shade(double distance, int color)
{
	int	t;
	int	r;
	int	g;
	int	b;

	if (distance < 0)
		distance = 0;
	if (distance > 1)
		distance = 1;
	t = get_t(color);
	r = get_r(color) * (1 - distance);
	g = get_g(color) * (1 - distance);
	b = get_b(color) * (1 - distance);
	return (create_trgb(t, r, g, b));
}

/**
 * is a function that accepts a int (color) as argument and
 * that will invert the color accordingly.
 */
int	get_opposite(int color)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = get_t(color);
	r = 0xFF - get_r(color);
	g = 0xFF - get_g(color);
	b = 0xFF - get_b(color);
	return (create_trgb(t, r, g, b));
}

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
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Colors!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);

	int		color;
	double	distance;
	int		shaded_color;
	int		opposite;

	color = create_trgb(0, 18, 52, 86);
	distance = 0.5;
	shaded_color = add_shade(distance, color);
	opposite = get_opposite(color);

	for (int y = 0; y <= 1080; y++)
	{
		for (int x = 0; x <= 1920; x++)
			my_mlx_pixel_put(&img, x, y, color);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	sleep(3);
	for (int y = 0; y <= 1080; y++)
	{
		for (int x = 0; x <= 1920; x++)
			my_mlx_pixel_put(&img, x, y, shaded_color);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	sleep(3);
	for (int y = 0; y <= 1080; y++)
	{
		for (int x = 0; x <= 1920; x++)
			my_mlx_pixel_put(&img, x, y, opposite);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	sleep(3);
	mlx_loop(mlx);
}

// int	main(void)
// {
// 	int		color;
// 	double	distance;
// 	int		shaded_color;
// 	int		opposite;

// 	color = create_trgb(0, 18, 52, 86);
// 	distance = 0.5;
// 	shaded_color = add_shade(distance, color);
// 	opposite = get_opposite(color);
// 	printf("Cor original: #%06X\n", color);
// 	printf("Cor sombreamento: #%06X\n", shaded_color);
// 	printf("Cor original: #%06X\n", color);
// 	printf("Cor invertida: #%06X\n", opposite);
// 	return (0);
// }
