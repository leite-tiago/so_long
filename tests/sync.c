// gcc -o sync tests/sync.c -I ./mlx -I /opt/X11/include -L ./mlx -L /opt/X11/lib -lmlx -lXext -lX11 -lm && ./sync

#define MLX_SYNC_IMAGE_WRITABLE		1
#define MLX_SYNC_WIN_FLUSH_CMD		2
#define MLX_SYNC_WIN_CMD_COMPLETED	3

// int	mlx_sync(int cmd, void *ptr);

#include <mlx.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	int		win_width;
	int		win_height;
	int		img_width;
	int		img_height;
}				t_vars;

// Draw a circle in the image
void	draw_circle(t_vars *vars, int cx, int cy, int radius, int color)
{
	int	x, y;
	int	distance;

	for (y = 0; y < vars->img_height; y++)
	{
		for (x = 0; x < vars->img_width; x++)
		{
			distance = sqrt(pow(x - cx, 2) + pow(y - cy, 2));
			if (distance <= radius)
				*(int *)(vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8))) = color;
		}
	}
}

// Clear the image (set all pixels to black)
void	clear_image(t_vars *vars)
{
	int	x, y;

	for (y = 0; y < vars->img_height; y++)
		for (x = 0; x < vars->img_width; x++)
			*(int *)(vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8))) = 0x000000;
}

// Key event handler
int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307) // ESC
		exit(0);
	else if (keycode == 119) // W
		vars->y -= 10;
	else if (keycode == 97) // A
		vars->x -= 10;
	else if (keycode == 115) // S
		vars->y += 10;
	else if (keycode == 100) // D
		vars->x += 10;
	return (0);
}

// Render the frame
int	render_frame(t_vars *vars)
{
	clear_image(vars); // Clear the image for the new frame
	draw_circle(vars, vars->x, vars->y, 20, 0x00FF0000); // Draw the circle
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, vars->img); // Sync the changes to the image
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0); // Display the image
	mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, vars->win); // Flush window updates
	return (0);
}

int	main(void)
{
	t_vars	vars;

	// Initialize variables
	vars.mlx = mlx_init();
	vars.win_width = 800;
	vars.win_height = 600;
	vars.win = mlx_new_window(vars.mlx, vars.win_width, vars.win_height, "Circle Game");
	vars.img = mlx_new_image(vars.mlx, vars.win_width, vars.win_height);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	vars.img_width = vars.win_width;
	vars.img_height = vars.win_height;
	vars.x = vars.win_width / 2; // Start in the center of the window
	vars.y = vars.win_height / 2;

	// Register hooks
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop_hook(vars.mlx, render_frame, &vars);

	// Start the event loop
	mlx_loop(vars.mlx);
}
