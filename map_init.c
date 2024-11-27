/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:57:09 by tborges-          #+#    #+#             */
/*   Updated: 2024/11/27 10:53:31 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_map
{
	char	**data;
	int		rows;
	int		cols;
	int		count_p;
	int		count_e;
	int		count_c;
}			t_map;

void		error_exit(const char *message, t_map *map);

/**
 * Check if the file extension is .ber.
 */
void	check_file_extension(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strcmp(filename + len - 4, ".ber") != 0)
		ft_printf("Error\nInvalid file extension. Must be .ber\n"), exit(1);
}

/**
 * Count the number of lines in a file.
 */
int	count_lines_in_file(int fd)
{
	int		lines;
	char	*line;

	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	if (lines == 0)
		ft_printf("Error\nEmpty map file\n"), exit(1);
	close(fd);
	return (lines);
}

/**
 * Read the map from a file and store it in a t_map struct.
 */
void	read_map_from_file(const char *filename, t_map *map)
{
	int	fd;
	int	i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_printf("Error\nFailed to open file: %s\n", strerror(errno)), exit(1);
	map->rows = count_lines_in_file(fd);
	map->data = malloc(sizeof(char *) * map->rows);
	if (!map->data)
		ft_printf("Error\nMemory allocation failed\n"), exit(1);
	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < map->rows)
	{
		map->data[i] = get_next_line(fd);
		if (!map->data[i])
			ft_printf("Error\nFailed to read line from file\n"), exit(1);
		if (map->cols == 0)
			map->cols = ft_strlen(map->data[i]);
		else if ((int)ft_strlen(map->data[i]) != map->cols)
			error_exit("Map is not rectangular", map);
		i++;
	}
	close(fd);
}

/**
 * Initialize the map.
 */
void	init_map(int argc, char **argv, t_map *map)
{
	if (argc != 2)
		ft_printf("Error\nUsage: %s <map_file.ber>\n", argv[0]), exit(1);
	check_file_extension(argv[1]);
	ft_memset(map, 0, sizeof(t_map));
	read_map_from_file(argv[1], map);
	validate_map(map);
}
