/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:02:14 by tborges-          #+#    #+#             */
/*   Updated: 2024/12/01 22:48:04 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h> // open and close files
#include <mlx.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_map
{
	char **data;
	int rows;
	int cols;
	int count_p;
	int count_e;
	int count_c;
}				t_map;

typedef struct s_flood
{
	int			collectibles;
	int			exit_found;
}				t_flood;

typedef struct s_textures
{
	void		*wall;
	void		*floor;
	void		*player;
	void		*collectible;
	void		*exit;
}				t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_textures	textures;
	t_map		map;
}				t_game;

#define SPRITE_SIZE 32

// events
enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// map components
#define VALID_CHARS "01CEP"

// error
void			error_exit(const char *message);
void			error_exit_map(const char *message, t_map *map);
void			error_exit_game(const char *message, t_game *game);

// frees
void			free_map(t_map *map);
void			free_copy(char **copy, int rows);
void			free_textures(t_game *game);
void			free_game(t_game *game);

// map_init
void			init_map(int argc, char **argv, t_map *map);
void			check_file_extension(const char *filename);
int				count_lines_in_file(int fd);
int				open_map_file(const char *filename);
void			allocate_map_data(t_map *map);

// map_read
void			read_map_from_file(const char *filename, t_map *map);
void			read_map_line(int fd, t_map *map, int index);

// map_validation
void			validate_map(t_map *map);
void			validate_map_format(t_map *map);
void			validate_borders(t_map *map);
void			validate_path(t_map *map);

// map_validation_aux
void			find_player_and_fill(char **copy, t_map *map, t_flood *flood);
void			copy_map(char **copy, t_map *map);
void			flood_fill(char **map, int x, int y, t_flood *flood);
int				is_valid_char(char c);

// render
void			render_map(t_game *game);
void			render_tile(t_game *game, char tile, int x, int y);
void			load_textures(t_game *game);

// input
void	move_player(t_map map, char *direction);
